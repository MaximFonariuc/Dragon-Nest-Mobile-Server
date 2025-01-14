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
#define TiYan_MobileQQ_App_ID  ""							//手Q AppID
#define TiYan_MobileQQ_App_Key ""					//手Q AppKey
#define TiYan_WeChat_App_ID  ""					//微信AppID
#define TiYan_WeChat_App_Key  ""	//微信Appkey

#define TiYan_PayAppKeyTestAnd "" //安卓沙箱
#define TiYan_PayAppKeyAnd "" //安卓现网
#define TiYan_PayAppKeyTestIos "" //ios沙箱
#define TiYan_PayAppKeyIos	"" //ios现网

#define TiYan_MidasAndroidAppid ""
#define TiYan_MidasIosAppid ""
#define TiYan_PayBuyGoodsAndroidAppid "" //体验服没有给id
#define TiYan_PayBuyGoodsIosAppid "" //体验服没有给id

#define TiYan_PayBuyGoodsAppKeyTestAnd "" //直购安卓沙箱（体验服没有给）
#define TiYan_PayBuyGoodsAppKeyAnd "" //直购安卓现网（体验服没有给）
#define TiYan_PayBuyGoodsAppKeyTestIos "" //直购ios沙箱（体验服没有给）
#define TiYan_PayBuyGoodsAppKeyIos	"" //直购ios现网（体验服没有给）


//Normal
#define Normal_MobileQQ_App_ID  ""						//手Q AppID
#define Normal_MobileQQ_App_Key ""					//手Q AppKey
#define Normal_WeChat_App_ID  ""					//微信AppID
#define Normal_WeChat_App_Key  ""	//微信Appkey

#define Normal_PayAppKeyTestAnd "" //安卓沙箱
#define Normal_PayAppKeyAnd "" //安卓现网
#define Normal_PayAppKeyTestIos "" //ios沙箱
#define Normal_PayAppKeyIos	"" //ios现网

#define Normal_MidasAndroidAppid "" //充值安卓appid
#define Normal_MidasIosAppid "" //充值ios appid
#define Normal_PayBuyGoodsAndroidAppid "" //直购安卓appid
#define Normal_PayBuyGoodsIosAppid "" //直购ios appid

#define Normal_PayBuyGoodsAppKeyTestAnd "" //直购安卓沙箱
#define Normal_PayBuyGoodsAppKeyAnd "" //直购安卓现网
#define Normal_PayBuyGoodsAppKeyTestIos "" //直购ios沙箱
#define Normal_PayBuyGoodsAppKeyIos	"" //直购ios现网


//RealUse
#define MobileQQ_App_ID				(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_MobileQQ_App_ID			:	Normal_MobileQQ_App_ID)		//手Q AppID
#define MobileQQ_App_Key			(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_MobileQQ_App_Key			:	Normal_MobileQQ_App_Key)	//手Q AppKey
#define WeChat_App_ID				(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_WeChat_App_ID			:	Normal_WeChat_App_ID)		//微信AppID
#define WeChat_App_Key				(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_WeChat_App_Key			:	Normal_WeChat_App_Key)		//微信Appkey

#define PayAppKeyTestAnd			(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayAppKeyTestAnd			:	Normal_PayAppKeyTestAnd)	//安卓沙箱
#define PayAppKeyAnd				(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayAppKeyAnd				:	Normal_PayAppKeyAnd)		//安卓现网
#define PayAppKeyTestIos			(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayAppKeyTestIos			:	Normal_PayAppKeyTestIos)	//ios沙箱
#define PayAppKeyIos				(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayAppKeyIos				:	Normal_PayAppKeyIos)		//ios现网

#define MidasAndroidAppid			(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_MidasAndroidAppid		:	Normal_MidasAndroidAppid)	//充值安卓appid
#define MidasIosAppid				(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_MidasIosAppid			:	Normal_MidasIosAppid)		//充值ios appid
#define PayBuyGoodsAndroidAppid		(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayBuyGoodsAndroidAppid	:	Normal_PayBuyGoodsAndroidAppid)		//直购安卓appid
#define PayBuyGoodsIosAppid			(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayBuyGoodsIosAppid		:	Normal_PayBuyGoodsIosAppid)			//直购ios appid

#define PayBuyGoodsAppKeyTestAnd	(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayBuyGoodsAppKeyTestAnd :	Normal_PayBuyGoodsAppKeyTestAnd)	//直购安卓沙箱
#define PayBuyGoodsAppKeyAnd		(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayBuyGoodsAppKeyAnd		:	Normal_PayBuyGoodsAppKeyAnd)		//直购安卓现网
#define PayBuyGoodsAppKeyTestIos	(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayBuyGoodsAppKeyTestIos :	Normal_PayBuyGoodsAppKeyTestIos)	//直购ios沙箱
#define PayBuyGoodsAppKeyIos		(CAppConfig::Instance()->GetTag() == APP_TAG_TIYAN ? TiYan_PayBuyGoodsAppKeyIos		:	Normal_PayBuyGoodsAppKeyIos)		//直购ios现网


//心悦大R代充只有ios的;
#define XinYueRPayIosAppid ""
#define XinYueRPayAppkeyTestIos ""
#define XinYueRPayAppkeyIos ""

#define XinGeAccessIdIOS 2296009683							// 信鸽ios access_id
#define XinGeAccessIdAnd 2196009683							// 信鸽android access_id
#define XinGeSecretKeyIOS "xa0seqAScOhSsgrm"					// 信鸽ios secret_key
#define XinGeSecretKeyAnd "xa0seqAScOhSsgrm"					// 信鸽android secret_key

#endif