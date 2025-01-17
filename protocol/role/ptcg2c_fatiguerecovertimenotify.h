﻿#ifndef __PTCG2C_FATIGUERECOVERTIMENOTIFY_H__
#define __PTCG2C_FATIGUERECOVERTIMENOTIFY_H__

// generate by ProtoGen at date: 2015/7/30 15:18:22

#include "protocol.h"
#include "pb/project.pb.h"

#define PTCG2C_FATIGUERECOVERTIMENOTIFY_TYPE 14296

class PtcG2C_FatigueRecoverTimeNotify : public CProtocol
{
public:
    explicit PtcG2C_FatigueRecoverTimeNotify() : CProtocol(PTCG2C_FATIGUERECOVERTIMENOTIFY_TYPE)
    {
		m_message = &m_Data;
    }

    virtual ~PtcG2C_FatigueRecoverTimeNotify()
    {
    }

    virtual void Process(UINT32 dwConnID);

public:
	KKSG::FatigueRecoverTimeInfo m_Data;
};

#endif