﻿#ifndef __RPCC2G_GMCOMMAND_H__
#define __RPCC2G_GMCOMMAND_H__

// generate by ProtoGen at date: 2016/10/28 22:23:17

#include "crpc.h"
#include "pb/project.pb.h"

using namespace KKSG;

#define RPCC2G_GMCOMMAND_TYPE 3248

class RpcC2G_GMCommand : public CRpc
{
private:

	RpcC2G_GMCommand():CRpc(RPCC2G_GMCOMMAND_TYPE)
	{
        m_dwTimeout = 5000;
		m_ArgPtr = &m_oArg;
		m_ResPtr = &m_oRes;
	}

public:
	static RpcC2G_GMCommand *CreateRpc()
	{
		return new RpcC2G_GMCommand;
	}

	virtual RpcEndType GetEndType() const;
	virtual void Process(UINT32 dwConnID);

private:
	// implemention as client
	void OnReply(const GMCmdArg &roArg, const GMCmdRes &roRes, const CUserData &roUserData);
	void OnTimeout(const GMCmdArg &roArg, const CUserData &roUserData);

	// implemention as server
	void OnCall(const GMCmdArg &roArg, GMCmdRes &roRes);
	void OnDelayReplyRpc(const GMCmdArg &roArg, GMCmdRes &roRes, const CUserData &roUserData);

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
	GMCmdArg m_oArg;
	GMCmdRes m_oRes;
};

#endif
