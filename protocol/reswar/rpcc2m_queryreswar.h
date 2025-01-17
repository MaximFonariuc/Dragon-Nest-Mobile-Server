﻿#ifndef __RPCC2M_QUERYRESWAR_H__
#define __RPCC2M_QUERYRESWAR_H__

// generate by ProtoGen at date: 2016/11/2 23:01:02

#include "crpc.h"
#include "pb/project.pb.h"

using namespace KKSG;

#define RPCC2M_QUERYRESWAR_TYPE 41509

class RpcC2M_QueryResWar : public CRpc
{
private:

	RpcC2M_QueryResWar():CRpc(RPCC2M_QUERYRESWAR_TYPE)
	{
        m_dwTimeout = 5000;
		m_ArgPtr = &m_oArg;
		m_ResPtr = &m_oRes;
	}

public:
	static RpcC2M_QueryResWar *CreateRpc()
	{
		return new RpcC2M_QueryResWar;
	}

	virtual RpcEndType GetEndType() const;
	virtual void Process(UINT32 dwConnID);

private:
	// implemention as client
	void OnReply(const QueryResWarArg &roArg, const QueryResWarRes &roRes, const CUserData &roUserData);
	void OnTimeout(const QueryResWarArg &roArg, const CUserData &roUserData);

	// implemention as server
	void OnCall(const QueryResWarArg &roArg, QueryResWarRes &roRes);
	void OnDelayReplyRpc(const QueryResWarArg &roArg, QueryResWarRes &roRes, const CUserData &roUserData);

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
	QueryResWarArg m_oArg;
	QueryResWarRes m_oRes;
};

#endif
