#ifndef _H_APP_ID_H__
#define _H_APP_ID_H__


enum EAppTag
{
	APP_TAG_NORMAL = 0,
	APP_TAG_TIYAN,
};

class CAppConfig
{
	CAppConfig():m_nAppTag(APP_TAG_NORMAL){}
	~CAppConfig(){}
	DECLARE_SINGLETON(CAppConfig);
public:
	bool Init();
	void Uninit();

	EAppTag	GetTag() const { return m_nAppTag; }
private:
	EAppTag	m_nAppTag;
};


//TiYanTest
#define TiYan_MobileQQ_App_ID  ""							//��Q AppID
#define TiYan_MobileQQ_App_Key ""					//��Q AppKey
#define TiYan_WeChat_App_ID  ""					//΢��AppID
#define TiYan_WeChat_App_Key  ""	//΢��Appkey

#define TiYan_PayAppKeyTestAnd "" //��׿ɳ��
#define TiYan_PayAppKeyAnd "" //��׿����
#define TiYan_PayAppKeyTestIos "" //iosɳ��
#define TiYan_PayAppKeyIos	"" //ios����

#define TiYan_MidasAndroidAppid ""
#define TiYan_MidasIosAppid ""
#define TiYan_PayBuyGoodsAndroidAppid "" //�����û�и�id
#define TiYan_PayBuyGoodsIosAppid "" //�����û�и�id

#define TiYan_PayBuyGoodsAppKeyTestAnd "" //ֱ����׿ɳ�䣨�����û�и���
#define TiYan_PayBuyGoodsAppKeyAnd "" //ֱ����׿�����������û�и���
#define TiYan_PayBuyGoodsAppKeyTestIos "" //ֱ��iosɳ�䣨�����û�и���
#define TiYan_PayBuyGoodsAppKeyIos	"" //ֱ��ios�����������û�и���


//Normal
#define Normal_MobileQQ_App_ID  ""						//��Q AppID
#define Normal_MobileQQ_App_Key ""					//��Q AppKey
#define Normal_WeChat_App_ID  ""					//΢��AppID
#define Normal_WeChat_App_Key  ""	//΢��Appkey

#define Normal_PayAppKeyTestAnd "" //��׿ɳ��
#define Normal_PayAppKeyAnd "" //��׿����
#define Normal_PayAppKeyTestIos "" //iosɳ��
#define Normal_PayAppKeyIos	"" //ios����

#define Normal_MidasAndroidAppid "" //��ֵ��׿appid
#define Normal_MidasIosAppid "" //��ֵios appid
#define Normal_PayBuyGoodsAndroidAppid "" //ֱ����׿appid
#define Normal_PayBuyGoodsIosAppid "" //ֱ��ios appid

#define Normal_PayBuyGoodsAppKeyTestAnd "" //ֱ����׿ɳ��
#define Normal_PayBuyGoodsAppKeyAnd "" //ֱ����׿����
#define Normal_PayBuyGoodsAppKeyTestIos "" //ֱ��iosɳ��
#define Normal_PayBuyGoodsAppKeyIos	"" //ֱ��ios����


//RealUse
#define MobileQQ_App_ID				(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_MobileQQ_App_ID			:	Normal_MobileQQ_App_ID)		//��Q AppID
#define MobileQQ_App_Key			(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_MobileQQ_App_Key			:	Normal_MobileQQ_App_Key)	//��Q AppKey
#define WeChat_App_ID				(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_WeChat_App_ID			:	Normal_WeChat_App_ID)		//΢��AppID
#define WeChat_App_Key				(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_WeChat_App_Key			:	Normal_WeChat_App_Key)		//΢��Appkey

#define PayAppKeyTestAnd			(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayAppKeyTestAnd			:	Normal_PayAppKeyTestAnd)	//��׿ɳ��
#define PayAppKeyAnd				(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayAppKeyAnd				:	Normal_PayAppKeyAnd)		//��׿����
#define PayAppKeyTestIos			(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayAppKeyTestIos			:	Normal_PayAppKeyTestIos)	//iosɳ��
#define PayAppKeyIos				(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayAppKeyIos				:	Normal_PayAppKeyIos)		//ios����

#define MidasAndroidAppid			(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_MidasAndroidAppid		:	Normal_MidasAndroidAppid)	//��ֵ��׿appid
#define MidasIosAppid				(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_MidasIosAppid			:	Normal_MidasIosAppid)		//��ֵios appid
#define PayBuyGoodsAndroidAppid		(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayBuyGoodsAndroidAppid	:	Normal_PayBuyGoodsAndroidAppid)		//ֱ����׿appid
#define PayBuyGoodsIosAppid			(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayBuyGoodsIosAppid		:	Normal_PayBuyGoodsIosAppid)			//ֱ��ios appid

#define PayBuyGoodsAppKeyTestAnd	(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayBuyGoodsAppKeyTestAnd :	Normal_PayBuyGoodsAppKeyTestAnd)	//ֱ����׿ɳ��
#define PayBuyGoodsAppKeyAnd		(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayBuyGoodsAppKeyAnd		:	Normal_PayBuyGoodsAppKeyAnd)		//ֱ����׿����
#define PayBuyGoodsAppKeyTestIos	(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayBuyGoodsAppKeyTestIos :	Normal_PayBuyGoodsAppKeyTestIos)	//ֱ��iosɳ��
#define PayBuyGoodsAppKeyIos		(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayBuyGoodsAppKeyIos		:	Normal_PayBuyGoodsAppKeyIos)		//ֱ��ios����


//���ô�R����ֻ��ios��;
#define XinYueRPayIosAppid ""
#define XinYueRPayAppkeyTestIos ""
#define XinYueRPayAppkeyIos ""

#define XinGeAccessIdIOS 2296009683							// �Ÿ�ios access_id
#define XinGeAccessIdAnd 2196009683							// �Ÿ�android access_id
#define XinGeSecretKeyIOS "xa0seqAScOhSsgrm"					// �Ÿ�ios secret_key
#define XinGeSecretKeyAnd "xa0seqAScOhSsgrm"					// �Ÿ�android secret_key

#endif