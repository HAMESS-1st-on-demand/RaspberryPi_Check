#include <wiringPi.h>         // wiringPi 라이브러리 사용
#include <stdio.h>            // 표준입출력용 라이브러리  
#include <stdlib.h>           // 표준 유틸리티용 라이브러리
#include <stdint.h>           // 정수 자료형 라이브러리

#define MAX_TIMINGS	85        // 최대 신호 추출 개수
#define DHT_PIN		2	      // GPIO로 사용할 핀 번호

int data[5] = { 0, 0, 0, 0, 0 };       // 온습도 및 checksum 데이터 저장용 변수 배열

void read_dht_data()                    // dht데이터 읽기 함수
{
	uint8_t laststate	= HIGH;          // DHT핀의 상태 저장용 변수(현재 신호가 HIGH인지 LOW인지 확인하기 위한 용도)
	uint8_t counter		= 0;             // 신호의 길이를 측정하기 위한 카운터 변수
	uint8_t j			= 0, i;          // 40개의 신호 인덱스 용 변수

	data[0] = data[1] = data[2] = data[3] = data[4] = 0;    //초기 데이터 값은 0으로 지정

	/* DHT11센서와의 통신을 개시하기 위해 DATA핀을 18ms동안 LOW로 출력 */
	pinMode( DHT_PIN, OUTPUT );
	digitalWrite( DHT_PIN, LOW );
	delay( 18 );

	/* 핀을 입력모드로 설정해서 DHT11로 부터 응답을 기다림 */
	pinMode( DHT_PIN, INPUT );

	/* DHT11에서 오는 신호 검출 및 데이터비트 추출 */
	for ( i = 0; i < MAX_TIMINGS; i++ )       // 총 85번 동안 신호를 확인
	{
		counter = 0;                           // 초기 카운터는 0
		while ( digitalRead( DHT_PIN ) == laststate ) //DHT핀의 신호를 읽어서 현재 지정한 DATA핀 신호와 같은 동안==즉 신호의 변환이 없는 동안
		{
			counter++;                              // 카운터 변수 1 증가
			delayMicroseconds( 1 );                 // 1uS(마이크로초) 동안 대기
			if ( counter == 255 )                  // 카운터가 255까지 도달하면, 즉 너무 오래 동안 대기하면==오류가 생겼다는 의미 임
			{
				break;                              // 카운터 세기 중지
			}
		}
		laststate = digitalRead( DHT_PIN );       // 현재 핀 상태 저장

		if ( counter == 255 )                     // 카운터가 255이상 도달했다면, 데이터비트 수신 중지== for문 밖으로 나가서 처음부터 새로 받겠다는 의미임
			break;

		/* 첫번째 3개의 신호는 무시하고 짝수번째에 해당하는 신호길이를 읽어 0인지 1인지에 따라 온습도 변수에 저장
           첫번째 3개의 신호는 DHT11의 응답 용 신호로 실제 데이터 길이를 통해 정보를 수신하는 값이 아니므로 무시함.
           짝수만 추출하는 이유는 짝수 번째의 신호 길이에 따라 해당 신호가 0을 의미하는지 1을 의미하는지를 나타냄. 
         */     
		if ( (i >= 4) && (i % 2 == 0) )   // 4번째 이후의 신호이면서 짝수번째 신호라면 
		{
			/* 가각의 데이터 비트를 온도 및 습도 변수에 하나씩 넣어줌 */
			data[j / 8] <<= 1;                    // 이진수의 자리수를 하나씩 옆으로 이동시킴
			if ( counter > 40 )                    // 카운터의 값이 16보다 크다면, 즉 신호의 길이가 길어서 비트 1로 인식된다면
				data[j / 8] |= 1;                  // 해당 비트는 1을 넣어줌
			j++;                                 // 다음 데이터를 위해 인덱스 값을 하나 증가 시킴
		}
	}

	/*
	 * 40비트를 다 확인했다면 (8비트 x 5 ) 체크섬 데이터와 오류체크를 해서
	 * 오류가 없으면 데이터를 출력함.
     */
	if ( (j >= 40) && (data[4] == ( (data[0] + data[1] + data[2] + data[3]) & 0xFF) ) )
	{        //에러가 없으면 습도 및 온도 출력
		printf( "Humidity = %d.%d %% Temperature = %d.%d C\n", data[0], data[1], data[2], data[3]);
	}else  {
		printf( "Data not good, skip\n" );      //에러 발생시 Data not good 메시지 출력
        printf( "Humidity = %d.%d %% Temperature = %d.%d C\n", data[0], data[1], data[2], data[3]);
	}
}

int main( void )
{
	printf( "Raspberry Pi DHT11 temperature/humidity test\n" );     

	if ( wiringPiSetupGpio() == -1 )    //라즈베리파이의 BCM GPIO 핀번호를 사용하겠다고 선언
		exit( 1 );

	while ( 1 )
	{
		read_dht_data();              // 온도 및 습도 데이터 획득 및 출력
		delay( 300 );                // 다음 읽기까지 2초 대기
	}

	return(0);
}