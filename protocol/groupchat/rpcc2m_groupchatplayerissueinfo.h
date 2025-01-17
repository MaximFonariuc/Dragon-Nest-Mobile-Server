﻿#ifndef __RPCC2M_GROUPCHATPLAYERISSUEINFO_H__
#define __RPCC2M_GROUPCHATPLAYERISSUEINFO_H__

// generate by ProtoGen at date: 2017/7/13 11:41:33

#include "crpc.h"
#include "pb/project.pb.h"

using namespace KKSG;

#define RPCC2M_GROUPCHATPLAYERISSUEINFO_TYPE 48317

class RpcC2M_GroupChatPlayerIssueInfo : public CRpc
{
private:

	RpcC2M_GroupChatPlayerIssueInfo():CRpc(RPCC2M_GROUPCHATPLAYERISSUEINFO_TYPE)
	{
        m_dwTimeout = 5000;
		m_ArgPtr = &m_oArg;
		m_ResPtr = &m_oRes;
	}

public:
	static RpcC2M_GroupChatPlayerIssueInfo *CreateRpc()
	{
		return new RpcC2M_GroupChatPlayerIssueInfo;
	}

	virtual RpcEndType GetEndType() const;
	virtual void Process(UINT32 dwConnID);

private:
	// implemention as client
	void OnReply(const GroupChatPlayerIssueInfoC2S &roArg, const GroupChatPlayerIssueInfoS2C &roRes, const CUserData &roUserData);
	void OnTimeout(const GroupChatPlayerIssueInfoC2S &roArg, const CUserData &roUserData);

	// implemention as server
	void OnCall(const GroupChatPlayerIssueInfoC2S &roArg, GroupChatPlayerIssueInfoS2C &roRes);
	void OnDelayReplyRpc(const GroupChatPlayerIssueInfoC2S &roArg, GroupChatPlayerIssueInfoS2C &roRes, const CUserData &roUserData);

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
	GroupChatPlayerIssueInfoC2S m_oArg;
	GroupChatPlayerIssueInfoS2C m_oRes;
};

#endif
