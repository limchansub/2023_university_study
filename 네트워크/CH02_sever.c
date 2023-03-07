#include <stdio.h>
#include <winSock2.h>

int main(void)
{
    WSADATA wasData;
    int ret, errorCode;

    ret = WSAStartup(MAKEWORD(2, 2), &wasData);
    if (ret == 0)
    {
        printf(">윈속 라이브러리 초기화 성공.\n");
    }
    else
    {
        errorCode = WSAGetLastError();
        printf("<ERROR> WSAStartup 오류 발생(code=%d)\n", errorCode);
        return 1; // exit(1);
    }
    SOCKET serverSocket;
    // IPv4 , 연결지향형: 손실없는 전송지원,
    serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // TCP

    if (serverSocket == INVALID_SOCKET)
    { // 오류상황..
        errorCode = WSAGetLastError();
        printf("<ERROR> socket 오류 발생(code=%d)\n", errorCode);
    }

    bind(); // 서버 주소 설정...

    listen(); // 서버 준비 완료..

    accept(); // 연결 수신

    recv();

    send();

    closesocket(serverSocket);

    WSACleanup();

    return 0;
}