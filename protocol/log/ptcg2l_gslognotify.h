#ifndef __PTCG2L_GSLOGNOTIFY_H__
#define __PTCG2L_GSLOGNOTIFY_H__

// generate by ProtoGen at date: 2015/8/12 11:38:23

#include "protocol.h"
#include "pb/project.pb.h"

#define PTCG2L_GSLOGNOTIFY_TYPE 58575

class PtcG2L_GSLogNotify : public CProtocol
{
public:
    explicit PtcG2L_GSLogNotify() : CProtocol(PTCG2L_GSLOGNOTIFY_TYPE)
    {
		m_message = &m_Data;
    }

    virtual ~PtcG2L_GSLogNotify()
    {
    }

    virtual void Process(UINT32 dwConnID);

public:
	KKSG::LogMsg m_Data;
};

#endif