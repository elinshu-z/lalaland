//客户端数据类型
class ClientSocket
{
public:
	ClientSocket()
	{
		_sockfd = sockfd;
		memset(_szMsgBuf, 0 ,sizeof(_szMsgBuf));
		_lastPos = 0;
	}

	SOCKET sockfd()
	{
		return _sockfd;
	}

	char* msgBuf()
	{
		return _szMsgBuf;
	}

	int getLastPos()
	{
		return _lastPos;
	}

	void setLastPos(int pos)
	{
		_lastPos = pos;
	}

	//发送数据
	int SendData(DataHeader* header)
	{
		if (header)
		{
			return send(_sockfd, (const char *)header, header->dataLength, 0)
		}
		return SOCKET_EORROR;
	}

private:
	// socket fd_set file desc set
	SOCKET _sockfd;
	//第二缓冲区 消息缓冲区
	char _szMsgBuf[RECV_BUFF_SIZE * 5];
	//消息缓冲区的数据尾部位置
	int _lastPos;
};

//网络事件接口
class INetEvent
{	
	//纯虚函数
	//客户端加入事件
	virtual void OnNetJoin(ClientSocket* pClient) = 0;
	//客户端离开事件
	virtual void OnNetLeave(ClientSocket* pClient) = 0;
	//客户端消息事件
	virtual void OnNetMsg(ClientSocket* pClient, DataHeader* header) = 0;
private:


};

class CellServer
{
public:
	CellServer(SOCKET sock = INVALID_SOCKET)
	{

	}

	~CellServer()
	{}

	void setEventObj()
	{}

	void Close()
	{}

	bool isRun()
	{}

	bool OnRun()
	{}

	char _szRecv[RECV_BUFF_SIZE] = {};
	//接收数据 处理粘包 拆分包
	int RecvData(ClientSocket* pClient)
	{}

	virtual void OnNetMsg(ClientSocket* pClient, DataHeader* header)
	{}
	void addClient(ClientSocket* pClient)
	{}

	void Start()
	{}

	size_t getClientCount()
	{}

private:
	SOCKET _sock;
	//正式客户队列
	std::vector<ClientSocket*> _clients;
	//缓冲客户队列
	std::vector<ClientSocket*> _clientsBuff;
	//缓冲队列锁
	std::mutex _mutex;
	std::thread _thread;
	//网络事件对象
	INetEvent* _pNetEvent;
};

class EasyTcpServer : public INetEvent
{};














