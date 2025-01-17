﻿#ifndef __RPCM2G_MSGIVEITEM_H__
#define __RPCM2G_MSGIVEITEM_H__

// generate by ProtoGen at date: 2017/6/24 16:32:11

#include "crpc.h"
#include "pb/project.pb.h"

using namespace KKSG;

#define RPCM2G_MSGIVEITEM_TYPE 43464

class RpcM2G_MsGiveItem : public CRpc
{
private:

	RpcM2G_MsGiveItem():CRpc(RPCM2G_MSGIVEITEM_TYPE)
	{
        m_dwTimeout = 5000;
		m_ArgPtr = &m_oArg;
		m_ResPtr = &m_oRes;
	}

public:
	static RpcM2G_MsGiveItem *CreateRpc()
	{
		return new RpcM2G_MsGiveItem;
	}

	virtual RpcEndType GetEndType() const;
	virtual void Process(UINT32 dwConnID);

private:
	// implemention as client
	void OnReply(const MsGiveItemArg &roArg, const MsGiveItemRes &roRes, const CUserData &roUserData);
	void OnTimeout(const MsGiveItemArg &roArg, const CUserData &roUserData);

	// implemention as server
	void OnCall(const MsGiveItemArg &roArg, MsGiveItemRes &roRes);
	void OnDelayReplyRpc(const MsGiveItemArg &roArg, MsGiveItemRes &roRes, const CUserData &roUserData);

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
	MsGiveItemArg m_oArg;
	MsGiveItemRes m_oRes;
};

#endif
