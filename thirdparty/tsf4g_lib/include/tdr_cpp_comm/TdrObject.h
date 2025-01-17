/* This file is generated by tdr. */
/* No manual modification is permitted. */

/* tdr version: 2.7.12 */

#ifndef TSF4G_TDR_TDR_BASE_H_
#define TSF4G_TDR_TDR_BASE_H_

#include "TdrPal.h"
#include "TdrBuf.h"
#include "TdrError.h"

namespace tsf4g_tdr
{


const int TDR_OBJECT_VERSION = 2;

class ITdrObject
{
    public:
        virtual ~ITdrObject() {}

    public:
        /* get ITdrObject base class version */
        virtual int getVersion() const;

    public:
        virtual int typeID() const = 0;
        virtual const char* typeName() const = 0;
        /* create new object */
        /* if p is NULL, use heap memory. Otherwise, use memory refered by p */
        virtual ITdrObject* newOne(void* p = NULL, size_t size = 0) const = 0;
        /* create new object and copy from *this */
        /* if p is NULL, use heap memory. Otherwise, use memory refered by p */
        virtual ITdrObject* clone(void* p = NULL, size_t size = 0) const = 0;

    public:
        virtual TdrError::ErrorType construct() = 0;

        virtual TdrError::ErrorType
        pack(TdrWriteBuf& destBuf, unsigned cutVer = 0) const;

        virtual TdrError::ErrorType
        pack(char* buffer, size_t size, size_t* usedSize = NULL, unsigned cutVer = 0) const;

        virtual TdrError::ErrorType
        unpack(TdrReadBuf& srcBuf, unsigned cutVer = 0);

        virtual TdrError::ErrorType
        unpack(const char* buffer, size_t size, size_t* usedSize = NULL, unsigned cutVer = 0);

        /* set indent = -1 to disable indent */
        virtual TdrError::ErrorType
        visualize(TdrWriteBuf& destBuf, int indent = 0, char separator = '\n') const;

        /* set indent = -1 to disable indent */
        virtual TdrError::ErrorType
        visualize(char* buffer, size_t size, size_t* usedSize = NULL, int indent = 0, char separator = '\n') const;

        virtual TdrError::ErrorType
        fromXmlFile(const char* file, TdrXmlFormat format = tsf4g_tdr::LIST_ENTRY, unsigned cutVer = 0);

        virtual TdrError::ErrorType
        fromXmlBuffer(const char* buffer, size_t size, TdrXmlFormat format = tsf4g_tdr::LIST_ENTRY, unsigned cutVer = 0);

        /* 'string' should be null-terminated and may be modified */
        virtual TdrError::ErrorType
        fromXmlString(char* string, TdrXmlFormat format = tsf4g_tdr::LIST_ENTRY, unsigned cutVer = 0);

        virtual TdrError::ErrorType
        toXmlFile(const char* file, TdrXmlFormat format = tsf4g_tdr::LIST_ENTRY, unsigned cutVer = 0) const;

        virtual TdrError::ErrorType
        toXmlFile(FILE* fp, TdrXmlFormat format = tsf4g_tdr::LIST_ENTRY, unsigned cutVer = 0) const;

        virtual TdrError::ErrorType
        toXmlBuffer(char* buffer, size_t size, size_t* usedSize = NULL,
                    TdrXmlFormat format = tsf4g_tdr::LIST_ENTRY, unsigned cutVer = 0) const;

        virtual TdrError::ErrorType
        packTLV(char* buffer, size_t size, size_t* usedSize = NULL, bool varint = true) const;

        virtual TdrError::ErrorType
        unpackTLV(const char* buffer, size_t size, size_t* usedSize = NULL);
        /* valid only for unpackTLV */
        virtual const char*
        getLastLostRequiredFields(char* message, size_t size) const;

        /* TDR_OBJECT_VERSION = 2 */
        virtual TdrError::ErrorType
        getTLVMaxPackedSize(size_t* size, bool varint = true) const;
};

struct TypeID2StaticNew
{
    int cmd;
    ITdrObject* (*constructor)(void*, size_t);
};

struct TypeStr2StaticNew
{
    const char* cmd;
    ITdrObject* (*constructor)(void*, size_t);
};

}
#endif
