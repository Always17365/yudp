#ifndef RUDP_SOCKET_H
#define RUDP_SOCKET_H

namespace YUDP {

    class RUDPSocket;

    enum RUDPSocketStatus
    {
        Connecting,     // During the connection phase
        Connected,      // We are connected
        Closing,        // During the closing phase
        ClosingACKed,   // When the tear down message has been ACKed
        Closed,         // The connection is closed / It is the default status
        Accepting
    };

    enum RUDPCongestionControl
    {
        // The older version of TCP
        TCPTahoe,

        TCPReno,

        // Experimental, but by default on some linux implementation
        TCPBIC,
        TCPCUBIC,
        UDT,

        // For test purpose
        Simple01
    };

    
    class RUDPSocketNetworkInformation
    {
    private:
        RUDPSocket *_rudp;

    public:
        RUDPSocketNetworkInformation(RUDPSocket *rudp);
        virtual ~RUDPSocketNetworkInformation();

        int getPathMTU();
        double getCongestionWindow();
        double getRTT();
        double getRTO();
        long getBandWidth();
    };

    class RUDPSocket {
        //---- Global
        static int LockTimeOut = -1;
        static int DefaultConnectionTimeOut = 60000;
        static int LastHandle = 0;
        //---- The Control thread that manage this socket
        int _controlThreadId = -1;

    };
}
#endif //:~ RUDP_SOCKET_H
