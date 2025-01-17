﻿#ifndef __RPCG2M_DAILYTASKREFRESHG2M_H__
#define __RPCG2M_DAILYTASKREFRESHG2M_H__

// generate by ProtoGen at date: 2017/9/19 15:54:19

#include "crpc.h"
#include "pb/project.pb.h"

using namespace KKSG;

#define RPCG2M_DAILYTASKREFRESHG2M_TYPE 22864

class RpcG2M_DailyTaskRefreshG2M : public CRpc
{
private:

	RpcG2M_DailyTaskRefreshG2M():CRpc(RPCG2M_DAILYTASKREFRESHG2M_TYPE)
	{
        m_dwTimeout = 5000;
		m_ArgPtr = &m_oArg;
		m_ResPtr = &m_oRes;
	}

public:
	static RpcG2M_DailyTaskRefreshG2M *CreateRpc()
	{
		return new RpcG2M_DailyTaskRefreshG2M;
	}

	virtual RpcEndType GetEndType() const;
	virtual void Process(UINT32 dwConnID);

private:
	// implemention as client
	void OnReply(const DailyTaskRefreshG2MArg &roArg, const DailyTaskRefreshG2MRes &roRes, const CUserData &roUserData);
	void OnTimeout(const DailyTaskRefreshG2MArg &roArg, const CUserData &roUserData);

	// implemention as server
	void OnCall(const DailyTaskRefreshG2MArg &roArg, DailyTaskRefreshG2MRes &roRes);
	void OnDelayReplyRpc(const DailyTaskRefreshG2MArg &roArg, DailyTaskRefreshG2MRes &roRes, const CUserData &roUserData);

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
	DailyTaskRefreshG2MArg m_oArg;
	DailyTaskRefreshG2MRes m_oRes;
};

#endif
