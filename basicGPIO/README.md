### GPIO 기본 문서

### 1. blink.c 

- 기본 LED를 켜는 코드

### 2. button.c

- bcm2835.h 사용해서 pin 20 으로 버튼 입력을 받는 코드

### 3. button_Int.c

- Interrupt 구현해서 진행하는 코드

#### 꿀팁!

```
$ gpio readall
```

- 다음의 명령어로 GPIO Port 확인이 가능하다.