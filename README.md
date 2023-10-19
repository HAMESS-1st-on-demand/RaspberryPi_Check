# Raspberry-_Pi_Check :floppy_disk:
라즈베리파이 GPIO 설정 확인하는 repository

--------------------

### 초기 설정

#### 1. Raspberry Pi Imager

- 32bit 운영체제 선택 
- hostname : <ipaddr id>
- username : <linux의 사용자 이름>
- pw : <linux 비밀번호>

#### 2. Setting for ssh 

- ssh.txt 파일 만들기 (빈 메모장 파일)
- wpa_supplicant.conf 파일 생성
    ```
    ctrl_interface=DIR=/var/run/wpa_supplicant  
    country=GB  
    update_config=1  
    network={  
    
        ssid="your_ssid"  
        psk="your_pw"  
        key_mgmt=WPA-PSK  
    }
    ```
- 다음의 코드 실행
    ```
    $ sudo raspi-config
    ```
- ssh enable


#### 3. Setting Remote-SSH in VS code

- Extension > Remote - SSH 설치 
- .ssh/config 파일 설정
    ```
    Host <사용자@ip주소>
    HostName <hostname>
    User <linux 사용자>
    ```
    
- 연결

#### 4. 초기 설정

```
    $ sudo apt-get update
    $ sudo apt-get upgrade
```

-----------------------

### 버전 확인

##### gcc version : 12.2.0
    - 기본 설치
##### git version : 2.39.2
    ```
        $ sudo apt-get install git
    ```
##### cmake version : 3.25.1
    ```
        $ sudo apt-get install cmake
    ```
##### wiringpi(gpio -v로 확인) : 2.5.2
    ```
        $ cd /tmp
        $wget https://project-downloads.drogon.net/wiringpi-latest.deb
        $ sudo dpkg -i wiringpi-latest.deb
    ```
    
##### bcm2835 library
    - 버전 확인
    ```
         $ grep "define BCM2835_VERSION" /usr/local/include/bcm2835.h
    ```
    
    - 설치 
    ```
        $ wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.68.tar.gz
        $ tar zxvf bcm2835-1.68.tar.gz
        $ cd bcm2835-1.68
        $ ./configure
        $ make
        $ sudo make check
        $ sudo make install
        $ gcc your_program.c -o output -lbcm2835
    ```
##### Linux 버전 Check(uname -a) : Linux raspberrypi22 6.1.0-rpi4-rpi-v8 #1 SMP PREEMPT Debian 1:6.1.54-1+rpt2 (2023-10-05) aarch64 GNU/Linux
