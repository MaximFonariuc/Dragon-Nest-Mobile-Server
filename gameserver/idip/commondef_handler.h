#ifndef _COMMONDEF_HANDLER_H__
#define _COMMONDEF_HANDLER_H__
#include "idip/idiphandler.h"
#include "idip/idiperrdesc.h"
#include "pb/project.pb.h"

GS_IDIP_HANDLER_COMMON_DECLARE(DelItem, IDIP_DO_DEL_ITEM_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(QueryBag, IDIP_QUERY_BAG_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(QueryEmblem, IDIP_QUERY_BADGE_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(QueryItem, IDIP_QUERY_EQUIPMENT_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(QueryRoleInfo, IDIP_QUERY_ROLE_INFO_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(UpdateAreanCoin, IDIP_DO_UPDATE_HONOUR_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(UpdateDiamond, IDIP_DO_UPDATE_DIAMOND_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(UpdateDragonCoin, IDIP_DO_UPDATE_DRAGON_GOLD_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(UpdateExp, IDIP_DO_UPDATE_EXP_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(UpdateFatigue, IDIP_DO_UPDATE_PHYSICAL_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(UpdateGold, IDIP_DO_UPDATE_GOLD_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(UpdateScore, IDIP_AQ_DO_CLEAR_SCORE_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(ZeroProfit, IDIP_AQ_DO_ZEROPROFIT_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(BanPlay, IDIP_AQ_DO_BAN_PLAY_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(RelievePunish, IDIP_AQ_DO_RELIEVE_PUNISH_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(QuerySpriteInfo, IDIP_QUERY_FAIRY_INFO_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(NameAct, IDIP_DO_NAME_ACT_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(DoXinyueRed, IDIP_DO_XINYUE_RED_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(QueryFashion, IDIP_QUERY_FASHION_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(QueryHorseInfo, IDIP_QUERY_HORSE_INFO_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(UpdateName, IDIP_DO_UPDATE_NAME_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(ItemChange, IDIP_DO_CHANGE_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(DoIdipRed, IDIP_DO_XIAOYUE_RED_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(DiamondConsumeToGame, IDIP_DO_COIN_CONSUME_TO_GAME_REQ)
GS_IDIP_HANDLER_COMMON_DECLARE(QueryFashionCompose, IDIP_QUERY_ROLE_CLOTHES_REQ)

#endif