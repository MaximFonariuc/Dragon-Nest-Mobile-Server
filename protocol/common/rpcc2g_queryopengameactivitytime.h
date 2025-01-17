﻿#ifndef __RPCC2G_QUERYOPENGAMEACTIVITYTIME_H__
#define __RPCC2G_QUERYOPENGAMEACTIVITYTIME_H__

// generate by ProtoGen at date: 2015/9/9 15:12:34

#include "crpc.h"
#include "pb/project.pb.h"

using namespace KKSG;

#define RPCC2G_QUERYOPENGAMEACTIVITYTIME_TYPE 24079

class RpcC2G_QueryOpenGameActivityTime : public CRpc
{
private:

	RpcC2G_QueryOpenGameActivityTime():CRpc(RPCC2G_QUERYOPENGAMEACTIVITYTIME_TYPE)
	{
        m_dwTimeout = 5000;
		m_ArgPtr = &m_oArg;
		m_ResPtr = &m_oRes;
	}

public:
	static RpcC2G_QueryOpenGameActivityTime *CreateRpc()
	{
		return new RpcC2G_QueryOpenGameActivityTime;
	}

	virtual RpcEndType GetEndType() const;
	virtual void Process(UINT32 dwConnID);

private:
	// implemention as client
	void OnReply(const QueryOpenGameArg &roArg, const QueryOpenGameRes &roRes, const CUserData &roUserData);
	void OnTimeout(const QueryOpenGameArg &roArg, const CUserData &roUserData);

	// implemention as server
	void OnCall(const QueryOpenGameArg &roArg, QueryOpenGameRes &roRes);
	void OnDelayReplyRpc(const QueryOpenGameArg &roArg, QueryOpenGameRes &roRes, const CUserData &roUserData);

	virtual void OnReplyTimeout() 
	{ 
		OnTimeout(m_oArg, m_oUser); 
	}

	virtual void OnDelayRpc(const CUserData &userData)
	{
		OnDelayReplyRpc( m_oArg, m_oRes, userData);
	}

	virtual CRpc *NewRpc() 
	{
		return CreateRpc();
	}

public:
	QueryOpenGameArg m_oArg;
	QueryOpenGameRes m_oRes;
};

#endif
