#pragma once
enum PacketID
{
    ID_NONE,             // 패킷 아이디가 지정되지 않았을 경우
    C2S_LOGIN_REQUEST,   // 클라이언트에서 서버로 로그인 요청
    S2C_LOGIN_RESPONSE,  // 서버에서 클라이언트로 로그인 응답

    C2S_SIGNUP_REQUEST,  // 클라이언트에서 서버로 회원가입 요청
    S2C_SIGNUP_RESPONSE, // 서버에서 클라이언트로 회원가입 응답

    C2S_LOGOUT_REQUEST,          // 클라이언트에서 서버로 로그아웃 요청

    C2S_CHAT_MESSAGE,    // 클라이언트에서 서버로 채팅 메시지 전송 요청
    S2C_CHAT_BROADCAST,  // 서버에서 클라이언트로 채팅 메시지 전송 (모든 채팅 참가자에게)

    C2S_ROOM_CREATE,     // 클라이언트에서 서버로 채팅방 생성 요청
    C2S_ROOM_JOIN,       // 클라이언트에서 서버로 채팅방 입장 요청
    C2S_ROOM_LEAVE,      // 클라이언트에서 서버로 채팅방 퇴장 요청
    C2S_ROOM_DELETE,     // 클라이언트에서 서버로 채팅방 삭제 요청
    C2S_ROOM_USER_LIST   // 클라이언트에서 서버로 채팅방에 참가중인 사용자 리스트 요청
};
