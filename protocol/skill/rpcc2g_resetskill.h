﻿#ifndef __RPCC2G_RESETSKILL_H__
#define __RPCC2G_RESETSKILL_H__

// generate by ProtoGen at date: 2015/4/13 14:16:50

#include "crpc.h"
#include "pb/project.pb.h"

using namespace KKSG;

#define RPCC2G_RESETSKILL_TYPE 26941

class RpcC2G_ResetSkill : public CRpc
{
private:

	RpcC2G_ResetSkill():CRpc(RPCC2G_RESETSKILL_TYPE)
	{
        m_dwTimeout = 5000;
		m_ArgPtr = &m_oArg;
		m_ResPtr = &m_oRes;
	}

public:
	static RpcC2G_ResetSkill *CreateRpc()
	{
		return new RpcC2G_ResetSkill;
	}

	virtual RpcEndType GetEndType() const;
	virtual void Process(UINT32 dwConnID);

private:
	// implemention as client
	void OnReply(const ResetSkillArg &roArg, const ResetSkillRes &roRes, const CUserData &roUserData);
	void OnTimeout(const ResetSkillArg &roArg, const CUserData &roUserData);

	// implemention as server
	void OnCall(const ResetSkillArg &roArg, ResetSkillRes &roRes);
	void OnDelayReplyRpc(const ResetSkillArg &roArg, ResetSkillRes &roRes, const CUserData &roUserData);

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
	ResetSkillArg m_oArg;
	ResetSkillRes m_oRes;
};

#endif
