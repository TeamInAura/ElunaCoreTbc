/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 * Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "HookMgr.h"
#include "LuaEngine.h"

class ElunaPlayerScript : public PlayerScript
{
    public:
        ElunaPlayerScript() : PlayerScript("ElunaPlayerScript") { }

        void OnCharacterCreate(Player* player)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_CHARACTER_CREATE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_CHARACTER_CREATE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_CHARACTER_CREATE);
                sEluna.Push(sEluna.L, player);
                sEluna.ExecuteCall(2, 0);
            }
        }
        void OnCharacterDelete(uint32 guidlow)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_CHARACTER_DELETE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_CHARACTER_DELETE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_CHARACTER_DELETE);
                sEluna.Push(sEluna.L, guidlow);
                sEluna.ExecuteCall(2, 0);
            }
        }
        void OnLogin(Player* player)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_LOGIN].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_LOGIN].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_LOGIN);
                sEluna.Push(sEluna.L, player);
                sEluna.ExecuteCall(2, 0);
            }
        }
        void OnLogout(Player* player)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_LOGOUT].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_LOGOUT].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_LOGOUT);
                sEluna.Push(sEluna.L, player);
                sEluna.ExecuteCall(2, 0);
            }
        }
        void OnSpellCast(Player* player, Spell* spell, bool skipCheck)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_SPELL_CAST].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_SPELL_CAST].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_SPELL_CAST);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, spell);
                sEluna.Push(sEluna.L, skipCheck);
                sEluna.ExecuteCall(4, 0);
            }
        }
        void OnKillPlayer(Player* killer, Player* killed)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_KILL_PLAYER].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_KILL_PLAYER].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_KILL_PLAYER);
                sEluna.Push(sEluna.L, killer);
                sEluna.Push(sEluna.L, killed);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnKillCreature(Player* killer, Creature* killed)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_KILL_CREATURE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_KILL_CREATURE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_KILL_CREATURE);
                sEluna.Push(sEluna.L, killer);
                sEluna.Push(sEluna.L, killed);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnKilledByCreature(Creature* killer, Player* killed)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_KILLED_BY_CREATURE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_KILLED_BY_CREATURE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_KILLED_BY_CREATURE);
                sEluna.Push(sEluna.L, killer);
                sEluna.Push(sEluna.L, killed);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnDuelRequest(Player* target, Player* challenger)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_DUEL_REQUEST].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_DUEL_REQUEST].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_DUEL_REQUEST);
                sEluna.Push(sEluna.L, target);
                sEluna.Push(sEluna.L, challenger);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnDuelStart(Player* player1, Player* player2)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_DUEL_START].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_DUEL_START].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_DUEL_START);
                sEluna.Push(sEluna.L, player1);
                sEluna.Push(sEluna.L, player2);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnDuelEnd(Player* winner, Player* loser, DuelCompleteType type)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_DUEL_END].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_DUEL_END].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_DUEL_END);
                sEluna.Push(sEluna.L, winner);
                sEluna.Push(sEluna.L, loser);
                sEluna.Push(sEluna.L, type);
                sEluna.ExecuteCall(4, 0);
            }
        }
        void OnGiveXP(Player* player, uint32& amount, Unit* victim)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_GIVE_XP].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_GIVE_XP].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_GIVE_XP);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, amount);
                sEluna.Push(sEluna.L, victim);
                sEluna.ExecuteCall(4, 0);
            }
        }
        void OnLevelChange(Player* player, uint8 oldLevel)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_LEVEL_CHANGE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_LEVEL_CHANGE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_LEVEL_CHANGE);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, oldLevel);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnMoneyChange(Player* player, int32& amount)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_MONEY_CHANGE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_MONEY_CHANGE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_MONEY_CHANGE);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, amount);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnReputationChange(Player* player, uint32 factionId, int32& standing, bool incremental)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_REPUTATION_CHANGE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_REPUTATION_CHANGE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_REPUTATION_CHANGE);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, factionId);
                sEluna.Push(sEluna.L, standing);
                sEluna.Push(sEluna.L, incremental);
                sEluna.ExecuteCall(5, 0);
            }
        }
        void OnTalentsChange(Player* player, uint32 newPoints)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_TALENTS_CHANGE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_TALENTS_CHANGE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_TALENTS_CHANGE);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, newPoints);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnTalentsReset(Player* player, bool noCost)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_TALENTS_RESET].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_TALENTS_RESET].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_TALENTS_RESET);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, noCost);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_CHAT].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_CHAT].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_CHAT);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, msg);
                sEluna.Push(sEluna.L, type);
                sEluna.Push(sEluna.L, lang);
                if (sEluna.ExecuteCall(5, 1))
                {
                    if (!lua_isnoneornil(sEluna.L, 1))
                        msg = std::string(luaL_optstring(sEluna.L, 1, msg.c_str()));
                    sEluna.EndCall(1);
                }
            }
        }
        void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Player* receiver)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_WHISPER].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_WHISPER].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_WHISPER);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, msg);
                sEluna.Push(sEluna.L, type);
                sEluna.Push(sEluna.L, lang);
                sEluna.Push(sEluna.L, receiver);
                if (sEluna.ExecuteCall(6, 1))
                {
                    if (!lua_isnoneornil(sEluna.L, 1))
                        msg = std::string(luaL_optstring(sEluna.L, 1, msg.c_str()));
                    sEluna.EndCall(1);
                }
            }
        }
        void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Group* group)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_GROUP_CHAT].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_GROUP_CHAT].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_GROUP_CHAT);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, msg);
                sEluna.Push(sEluna.L, type);
                sEluna.Push(sEluna.L, lang);
                sEluna.Push(sEluna.L, group);
                if (sEluna.ExecuteCall(6, 1))
                {
                    if (!lua_isnoneornil(sEluna.L, 1))
                        msg = std::string(luaL_optstring(sEluna.L, 1, msg.c_str()));
                    sEluna.EndCall(1);
                }
            }
        }
        void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_GUILD_CHAT].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_GUILD_CHAT].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_GUILD_CHAT);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, msg);
                sEluna.Push(sEluna.L, type);
                sEluna.Push(sEluna.L, lang);
                sEluna.Push(sEluna.L, guild);
                if (sEluna.ExecuteCall(6, 1))
                {
                    if (!lua_isnoneornil(sEluna.L, 1))
                        msg = std::string(luaL_optstring(sEluna.L, 1, msg.c_str()));
                    sEluna.EndCall(1);
                }
            }
        }
        void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Channel* channel)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_CHANNEL_CHAT].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_CHANNEL_CHAT].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_CHANNEL_CHAT);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, msg);
                sEluna.Push(sEluna.L, type);
                sEluna.Push(sEluna.L, lang);
                sEluna.Push(sEluna.L, channel->GetName());
                if (sEluna.ExecuteCall(6, 1))
                {
                    if (!lua_isnoneornil(sEluna.L, 1))
                        msg = std::string(luaL_optstring(sEluna.L, 1, msg.c_str()));
                    sEluna.EndCall(1);
                }
            }
        }
        void OnEmote(Player* player, uint32 emote)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_EMOTE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_EMOTE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_EMOTE);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, emote);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnTextEmote(Player* player, uint32 textEmote, uint32 emoteNum, ObjectGuid guid)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_TEXT_EMOTE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_TEXT_EMOTE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_TEXT_EMOTE);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, textEmote);
                sEluna.Push(sEluna.L, emoteNum);
                sEluna.Push(sEluna.L, guid);
                sEluna.ExecuteCall(5, 0);
            }
        }
        void OnSave(Player* player)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_SAVE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_SAVE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_SAVE);
                sEluna.Push(sEluna.L, player);
                sEluna.ExecuteCall(2, 0);
            }
        }
        void OnBindToInstance(Player* player, Difficulty difficulty, uint32 mapid, bool permanent)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_BIND_TO_INSTANCE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_BIND_TO_INSTANCE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_BIND_TO_INSTANCE);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, difficulty);
                sEluna.Push(sEluna.L, mapid);
                sEluna.Push(sEluna.L, permanent);
                sEluna.ExecuteCall(5, 0);
            }
        }
        void OnUpdateZone(Player* player, uint32 newZone, uint32 newArea)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_UPDATE_ZONE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_UPDATE_ZONE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_UPDATE_ZONE);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, newZone);
                sEluna.Push(sEluna.L, newArea);
                sEluna.ExecuteCall(4, 0);
            }
        }
        void OnMapChange(Player* player)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_MAP_CHANGE].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_MAP_CHANGE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_MAP_CHANGE);
                sEluna.Push(sEluna.L, player);
                sEluna.ExecuteCall(2, 0);
            }
        }
        void OnEquip(Player* player, Item* item, uint8 bag, uint8 slot)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_EQUIP].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_EQUIP].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_EQUIP);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, item);
                sEluna.Push(sEluna.L, bag);
                sEluna.Push(sEluna.L, slot);
                sEluna.ExecuteCall(5, 0);
            }
        }
        void OnFirstLogin(Player* player)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_FIRST_LOGIN].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_FIRST_LOGIN].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_FIRST_LOGIN);
                sEluna.Push(sEluna.L, player);
                sEluna.ExecuteCall(2, 0);
            }
        }
        bool OnCanUseItem(Player* player, uint32 itemEntry)
        {
            bool result = true;
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_CAN_USE_ITEM].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_CAN_USE_ITEM].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_CAN_USE_ITEM);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, itemEntry);
                if (sEluna.ExecuteCall(3, 1))
                {
                    if (!lua_isnoneornil(sEluna.L, 1) && lua_toboolean(sEluna.L, 1))
                        result = luaL_optbool(sEluna.L, 1, result);
                    sEluna.EndCall(1);
                }
            }
            return !result;
        }
        void OnLootItem(Player* player, Item* item, uint32 count)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_LOOT_ITEM].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_LOOT_ITEM].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_LOOT_ITEM);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, item);
                sEluna.Push(sEluna.L, count);
                sEluna.ExecuteCall(4, 0);
            }
        }
        void OnEnterCombat(Player* player, Unit* enemy)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_ENTER_COMBAT].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_ENTER_COMBAT].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_ENTER_COMBAT);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, enemy);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnLeaveCombat(Player* player)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_LEAVE_COMBAT].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_LEAVE_COMBAT].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_LEAVE_COMBAT);
                sEluna.Push(sEluna.L, player);
                sEluna.ExecuteCall(2, 0);
            }
        }
        void OnRepop(Player* player)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_REPOP].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_REPOP].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_REPOP);
                sEluna.Push(sEluna.L, player);
                sEluna.ExecuteCall(2, 0);
            }
        }
        void OnResurrect(Player* player)
        {
            for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[PLAYER_EVENT_ON_RESURRECT].begin();
                itr != sEluna.ServerEventBindings[PLAYER_EVENT_ON_RESURRECT].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, PLAYER_EVENT_ON_RESURRECT);
                sEluna.Push(sEluna.L, player);
                sEluna.ExecuteCall(2, 0);
            }
        }
        void OnGossipSelect(Player* player, uint32 menuId, uint32 sender, uint32 action)
        {
            int bind = sEluna.playerGossipBindings->GetBind(menuId, GOSSIP_EVENT_ON_SELECT);
            if (bind)
            {
                player->PlayerTalkClass->ClearMenus();
                sEluna.BeginCall(bind);
                sEluna.Push(sEluna.L, GOSSIP_EVENT_ON_SELECT);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, menuId);
                sEluna.Push(sEluna.L, sender);
                sEluna.Push(sEluna.L, action);
                sEluna.ExecuteCall(5, 0);
            }
        }
        void OnGossipSelectCode(Player* player, uint32 menuId, uint32 sender, uint32 action, const char* code)
        {
            int bind = sEluna.playerGossipBindings->GetBind(menuId, GOSSIP_EVENT_ON_SELECT);
            if (bind)
            {
                player->PlayerTalkClass->ClearMenus();
                sEluna.BeginCall(bind);
                sEluna.Push(sEluna.L, GOSSIP_EVENT_ON_SELECT);
                sEluna.Push(sEluna.L, player);
                sEluna.Push(sEluna.L, menuId);
                sEluna.Push(sEluna.L, sender);
                sEluna.Push(sEluna.L, action);
                sEluna.Push(sEluna.L, code);
                sEluna.ExecuteCall(6, 0);
            }
        }
};

class ElunaGroupScript : public GroupScript
{
    public:
        ElunaGroupScript() : GroupScript("ElunaGroupScript") { }

        void OnAddMember(Group* group, uint64 guid)
        {
            for (std::vector<int>::const_iterator itr = sEluna.GroupEventBindings[GROUP_EVENT_ON_MEMBER_ADD].begin();
                itr != sEluna.GroupEventBindings[GROUP_EVENT_ON_MEMBER_ADD].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, GROUP_EVENT_ON_MEMBER_ADD);
                sEluna.Push(sEluna.L, group);
                sEluna.Push(sEluna.L, guid);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnInviteMember(Group* group, uint64 guid)
        {
            for (std::vector<int>::const_iterator itr = sEluna.GroupEventBindings[GROUP_EVENT_ON_MEMBER_INVITE].begin();
                itr != sEluna.GroupEventBindings[GROUP_EVENT_ON_MEMBER_INVITE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, GROUP_EVENT_ON_MEMBER_INVITE);
                sEluna.Push(sEluna.L, group);
                sEluna.Push(sEluna.L, guid);
                sEluna.ExecuteCall(3, 0);
            }
        }
        void OnRemoveMember(Group* group, uint64 guid, uint8 method, uint64 kicker, const char* reason) // Kicker and Reason not a part of Mangos, implement?
        {
            for (std::vector<int>::const_iterator itr = sEluna.GroupEventBindings[GROUP_EVENT_ON_MEMBER_REMOVE].begin();
                itr != sEluna.GroupEventBindings[GROUP_EVENT_ON_MEMBER_REMOVE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, GROUP_EVENT_ON_MEMBER_REMOVE);
                sEluna.Push(sEluna.L, group);
                sEluna.Push(sEluna.L, guid);
                sEluna.Push(sEluna.L, method);
                sEluna.Push(sEluna.L, kicker); // Kicker and Reason not a part of Mangos, implement?
                sEluna.Push(sEluna.L, reason);
                sEluna.ExecuteCall(6, 0);
            }
        }
        void OnChangeLeader(Group* group, uint64 newLeaderGuid, uint64 oldLeaderGuid)
        {
            for (std::vector<int>::const_iterator itr = sEluna.GroupEventBindings[GROUP_EVENT_ON_LEADER_CHANGE].begin();
                itr != sEluna.GroupEventBindings[GROUP_EVENT_ON_LEADER_CHANGE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, GROUP_EVENT_ON_LEADER_CHANGE);
                sEluna.Push(sEluna.L, group);
                sEluna.Push(sEluna.L, newLeaderGuid);
                sEluna.Push(sEluna.L, oldLeaderGuid);
                sEluna.ExecuteCall(4, 0);
            }
        }
        void OnDisband(Group* group)
        {
            for (std::vector<int>::const_iterator itr = sEluna.GroupEventBindings[GROUP_EVENT_ON_DISBAND].begin();
                itr != sEluna.GroupEventBindings[GROUP_EVENT_ON_DISBAND].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, GROUP_EVENT_ON_DISBAND);
                sEluna.Push(sEluna.L, group);
                sEluna.ExecuteCall(2, 0);
            }
        }
        void OnCreate(Group* group, uint64 leaderGuid, GroupType groupType)
        {
            for (std::vector<int>::const_iterator itr = sEluna.GroupEventBindings[GROUP_EVENT_ON_CREATE].begin();
                itr != sEluna.GroupEventBindings[GROUP_EVENT_ON_CREATE].end(); ++itr)
            {
                sEluna.BeginCall((*itr));
                sEluna.Push(sEluna.L, GROUP_EVENT_ON_CREATE);
                sEluna.Push(sEluna.L, group);
                sEluna.Push(sEluna.L, leaderGuid);
                sEluna.Push(sEluna.L, groupType);
                sEluna.ExecuteCall(4, 0);
            }
        }
};


void HookMgr::OnWorldUpdate(uint32 diff)
{
    sEluna.EventMgr.Update(diff);
    for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[WORLD_EVENT_ON_UPDATE].begin();
        itr != sEluna.ServerEventBindings[WORLD_EVENT_ON_UPDATE].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, WORLD_EVENT_ON_UPDATE);
        sEluna.Push(sEluna.L, diff);
        sEluna.ExecuteCall(2, 0);
    }
}

void HookMgr::HandleGossipSelectOption(Player* player, Item* item, uint32 sender, uint32 action, std::string code)
{
    int bind = sEluna.ItemGossipBindings->GetBind(item->GetEntry(), GOSSIP_EVENT_ON_SELECT);
    if (bind)
    {
        player->PlayerTalkClass->ClearMenus();
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, GOSSIP_EVENT_ON_SELECT);
        sEluna.Push(sEluna.L, player);
        sEluna.Push(sEluna.L, item);
        sEluna.Push(sEluna.L, sender);
        sEluna.Push(sEluna.L, action);
        if (code.empty())
            lua_pushnil(sEluna.L);
        else
            sEluna.Push(sEluna.L, code);
        sEluna.ExecuteCall(6, 0);
    }
}

void HookMgr::OnEngineRestart()
{
    for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[ELUNA_EVENT_ON_RESTART].begin();
        itr != sEluna.ServerEventBindings[ELUNA_EVENT_ON_RESTART].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, ELUNA_EVENT_ON_RESTART);
        sEluna.ExecuteCall(1, 0);
    }
}

// item
bool HookMgr::OnDummyEffect(Unit* caster, uint32 spellId, SpellEffectIndex effIndex, Item* target)
{
    int bind = sEluna.ItemEventBindings->GetBind(target->GetEntry(), ITEM_EVENT_ON_DUMMY_EFFECT);
    if (!bind)
        return false;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, ITEM_EVENT_ON_DUMMY_EFFECT);
    sEluna.Push(sEluna.L, caster);
    sEluna.Push(sEluna.L, spellId);
    sEluna.Push(sEluna.L, effIndex);
    sEluna.Push(sEluna.L, target);
    sEluna.ExecuteCall(5, 0);
    return true;
}

bool HookMgr::OnQuestAccept(Player* player, Item* item, Quest const* quest)
{
    int bind = sEluna.ItemEventBindings->GetBind(item->GetEntry(), ITEM_EVENT_ON_QUEST_ACCEPT);
    if (!bind)
        return false;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, ITEM_EVENT_ON_QUEST_ACCEPT);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, item);
    sEluna.Push(sEluna.L, quest);
    sEluna.ExecuteCall(4, 0);
    return true;
}

bool HookMgr::OnUse(Player* player, Item* item, SpellCastTargets const& targets)
{
    int bind1 = sEluna.ItemGossipBindings->GetBind(item->GetEntry(), GOSSIP_EVENT_ON_HELLO);
    int bind2 = sEluna.ItemEventBindings->GetBind(item->GetEntry(), ITEM_EVENT_ON_USE);
    if (!bind1 && !bind2)
        return false;
    if (bind1)
    {
        player->PlayerTalkClass->ClearMenus();
        sEluna.BeginCall(bind1);
        sEluna.Push(sEluna.L, GOSSIP_EVENT_ON_HELLO);
        sEluna.Push(sEluna.L, player);
        sEluna.Push(sEluna.L, item);
        sEluna.ExecuteCall(3, 0);
    }
    if (bind2)
    {
        sEluna.BeginCall(bind2);
        sEluna.Push(sEluna.L, ITEM_EVENT_ON_USE);
        sEluna.Push(sEluna.L, player);
        sEluna.Push(sEluna.L, item);
        if (GameObject* target = targets.getGOTarget())
            sEluna.Push(sEluna.L, target);
        else if (Item* target = targets.getItemTarget())
            sEluna.Push(sEluna.L, target);
        else if (Unit* target = targets.getUnitTarget())
            sEluna.Push(sEluna.L, target);
        else
            sEluna.Push(sEluna.L);
        sEluna.ExecuteCall(4, 0);
    }
    // player->SendEquipError((InventoryResult)83, pItem, NULL);
    return false;
}

bool HookMgr::OnExpire(Player* player, ItemPrototype const* proto)
{
    int bind = sEluna.ItemEventBindings->GetBind(proto->ItemId, ITEM_EVENT_ON_EXPIRE);
    if (!bind)
        return false;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, ITEM_EVENT_ON_EXPIRE);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, proto->ItemId);
    sEluna.ExecuteCall(3, 0);
    return true;
}
// creature
bool HookMgr::OnDummyEffect(Unit* caster, uint32 spellId, SpellEffectIndex effIndex, Creature* target)
{
    int bind = sEluna.CreatureEventBindings->GetBind(target->GetEntry(), CREATURE_EVENT_ON_DUMMY_EFFECT);
    if (!bind)
        return false;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, CREATURE_EVENT_ON_DUMMY_EFFECT);
    sEluna.Push(sEluna.L, caster);
    sEluna.Push(sEluna.L, spellId);
    sEluna.Push(sEluna.L, effIndex);
    sEluna.Push(sEluna.L, target);
    sEluna.ExecuteCall(5, 0);
    return true;
}

bool HookMgr::OnGossipHello(Player* player, Creature* creature)
{
    int bind = sEluna.CreatureGossipBindings->GetBind(creature->GetEntry(), GOSSIP_EVENT_ON_HELLO);
    if (!bind)
        return false;
    player->PlayerTalkClass->ClearMenus();
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GOSSIP_EVENT_ON_HELLO);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, creature);
    sEluna.ExecuteCall(3, 0);
    return true;
}

bool HookMgr::OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    int bind = sEluna.CreatureGossipBindings->GetBind(creature->GetEntry(), GOSSIP_EVENT_ON_SELECT);
    if (!bind)
        return false;
    player->PlayerTalkClass->ClearMenus();
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GOSSIP_EVENT_ON_SELECT);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, creature);
    sEluna.Push(sEluna.L, sender);
    sEluna.Push(sEluna.L, action);
    sEluna.ExecuteCall(5, 0);
    return true;
}

bool HookMgr::OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code)
{
    int bind = sEluna.CreatureGossipBindings->GetBind(creature->GetEntry(), GOSSIP_EVENT_ON_SELECT);
    if (!bind)
        return false;
    player->PlayerTalkClass->ClearMenus();
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GOSSIP_EVENT_ON_SELECT);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, creature);
    sEluna.Push(sEluna.L, sender);
    sEluna.Push(sEluna.L, action);
    sEluna.Push(sEluna.L, code);
    sEluna.ExecuteCall(6, 0);
    return true;
}

bool HookMgr::OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
{
    int bind = sEluna.CreatureEventBindings->GetBind(creature->GetEntry(), CREATURE_EVENT_ON_QUEST_ACCEPT);
    if (!bind)
        return false;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, CREATURE_EVENT_ON_QUEST_ACCEPT);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, creature);
    sEluna.Push(sEluna.L, quest);
    sEluna.ExecuteCall(4, 0);
    return true;
}

bool HookMgr::OnQuestSelect(Player* player, Creature* creature, Quest const* quest)
{
    int bind = sEluna.CreatureEventBindings->GetBind(creature->GetEntry(), CREATURE_EVENT_ON_QUEST_SELECT);
    if (!bind)
        return false;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, CREATURE_EVENT_ON_QUEST_SELECT);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, creature);
    sEluna.Push(sEluna.L, quest);
    sEluna.ExecuteCall(4, 0);
    return true;
}

bool HookMgr::OnQuestComplete(Player* player, Creature* creature, Quest const* quest)
{
    int bind = sEluna.CreatureEventBindings->GetBind(creature->GetEntry(), CREATURE_EVENT_ON_QUEST_COMPLETE);
    if (!bind)
        return false;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, CREATURE_EVENT_ON_QUEST_COMPLETE);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, creature);
    sEluna.Push(sEluna.L, quest);
    sEluna.ExecuteCall(4, 0);
    return true;
}

bool HookMgr::OnQuestReward(Player* player, Creature* creature, Quest const* quest)
{
    int bind = sEluna.CreatureEventBindings->GetBind(creature->GetEntry(), CREATURE_EVENT_ON_QUEST_REWARD);
    if (!bind)
        return false;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, CREATURE_EVENT_ON_QUEST_REWARD);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, creature);
    sEluna.Push(sEluna.L, quest);
    sEluna.ExecuteCall(4, 0);
    return true;
}

uint32 HookMgr::GetDialogStatus(Player* player, Creature* creature)
{
    int bind = sEluna.CreatureEventBindings->GetBind(creature->GetEntry(), CREATURE_EVENT_ON_DIALOG_STATUS);
    if (!bind)
        return 0;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, CREATURE_EVENT_ON_DIALOG_STATUS);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, creature);
    sEluna.ExecuteCall(3, 0);
    return 100;
}
// gameobject
bool HookMgr::OnDummyEffect(Unit* caster, uint32 spellId, SpellEffectIndex effIndex, GameObject* target)
{
    int bind = sEluna.GameObjectEventBindings->GetBind(target->GetEntry(), GAMEOBJECT_EVENT_ON_DUMMY_EFFECT);
    if (!bind)
        return false;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GAMEOBJECT_EVENT_ON_DUMMY_EFFECT);
    sEluna.Push(sEluna.L, caster);
    sEluna.Push(sEluna.L, spellId);
    sEluna.Push(sEluna.L, effIndex);
    sEluna.Push(sEluna.L, target);
    sEluna.ExecuteCall(5, 0);
    return true;
}

bool HookMgr::OnGossipHello(Player* player, GameObject* gameObject)
{
    int bind = sEluna.GameObjectGossipBindings->GetBind(gameObject->GetEntry(), GOSSIP_EVENT_ON_HELLO);
    if (!bind)
        return false;
    player->PlayerTalkClass->ClearMenus();
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GOSSIP_EVENT_ON_HELLO);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, gameObject);
    sEluna.ExecuteCall(3, 0);
    return true;
}

bool HookMgr::OnGossipSelect(Player* player, GameObject* gameObject, uint32 sender, uint32 action)
{
    int bind = sEluna.GameObjectGossipBindings->GetBind(gameObject->GetEntry(), GOSSIP_EVENT_ON_SELECT);
    if (!bind)
        return false;
    player->PlayerTalkClass->ClearMenus();
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GOSSIP_EVENT_ON_SELECT);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, gameObject);
    sEluna.Push(sEluna.L, sender);
    sEluna.Push(sEluna.L, action);
    sEluna.ExecuteCall(5, 0);
    return true;
}

bool HookMgr::OnGossipSelectCode(Player* player, GameObject* gameObject, uint32 sender, uint32 action, const char* code)
{
    int bind = sEluna.GameObjectGossipBindings->GetBind(gameObject->GetEntry(), GOSSIP_EVENT_ON_SELECT);
    if (!bind)
        return false;
    player->PlayerTalkClass->ClearMenus();
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GOSSIP_EVENT_ON_SELECT);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, gameObject);
    sEluna.Push(sEluna.L, sender);
    sEluna.Push(sEluna.L, action);
    sEluna.Push(sEluna.L, code);
    sEluna.ExecuteCall(6, 0);
    return true;
}

bool HookMgr::OnQuestAccept(Player* player, GameObject* gameObject, Quest const* quest)
{
    int bind = sEluna.GameObjectEventBindings->GetBind(gameObject->GetEntry(), GAMEOBJECT_EVENT_ON_QUEST_ACCEPT);
    if (!bind)
        return false;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GAMEOBJECT_EVENT_ON_QUEST_ACCEPT);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, gameObject);
    sEluna.Push(sEluna.L, quest);
    sEluna.ExecuteCall(4, 0);
    return true;
}

bool HookMgr::OnQuestComplete(Player* player, GameObject* gameObject, Quest const* quest)
{
    int bind = sEluna.CreatureEventBindings->GetBind(gameObject->GetEntry(), GAMEOBJECT_EVENT_ON_QUEST_COMPLETE);
    if (!bind)
        return false;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GAMEOBJECT_EVENT_ON_QUEST_COMPLETE);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, gameObject);
    sEluna.Push(sEluna.L, quest);
    sEluna.ExecuteCall(4, 0);
    return true;
}

bool HookMgr::OnQuestReward(Player* player, GameObject* gameObject, Quest const* quest)
{
    int bind = sEluna.GameObjectEventBindings->GetBind(gameObject->GetEntry(), GAMEOBJECT_EVENT_ON_QUEST_REWARD);
    if (!bind)
        return false;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GAMEOBJECT_EVENT_ON_QUEST_REWARD);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, gameObject);
    sEluna.Push(sEluna.L, quest);
    sEluna.ExecuteCall(4, 0);
    return true;
}

uint32 HookMgr::GetDialogStatus(Player* player, GameObject* gameObject)
{
    int bind = sEluna.GameObjectEventBindings->GetBind(gameObject->GetEntry(), GAMEOBJECT_EVENT_ON_DIALOG_STATUS);
    if (!bind)
        return 0;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GAMEOBJECT_EVENT_ON_DIALOG_STATUS);
    sEluna.Push(sEluna.L, player);
    sEluna.Push(sEluna.L, gameObject);
    sEluna.ExecuteCall(3, 0);
    return DIALOG_STATUS_UNDEFINED;
}

void HookMgr::OnDestroyed(GameObject* gameObject, Player* player)
{
    int bind = sEluna.GameObjectEventBindings->GetBind(gameObject->GetEntry(), GAMEOBJECT_EVENT_ON_DESTROYED);
    if (!bind)
        return;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GAMEOBJECT_EVENT_ON_DESTROYED);
    sEluna.Push(sEluna.L, gameObject);
    sEluna.Push(sEluna.L, player);
    sEluna.ExecuteCall(3, 0);
}

void HookMgr::OnDamaged(GameObject* gameObject, Player* player)
{
    int bind = sEluna.GameObjectEventBindings->GetBind(gameObject->GetEntry(), GAMEOBJECT_EVENT_ON_DAMAGED);
    if (!bind)
        return;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GAMEOBJECT_EVENT_ON_DAMAGED);
    sEluna.Push(sEluna.L, gameObject);
    sEluna.Push(sEluna.L, player);
    sEluna.ExecuteCall(3, 0);
}

void HookMgr::OnLootStateChanged(GameObject* gameObject, uint32 state, Unit* unit)
{
    int bind = sEluna.GameObjectEventBindings->GetBind(gameObject->GetEntry(), GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE);
    if (!bind)
        return;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE);
    sEluna.Push(sEluna.L, gameObject);
    sEluna.Push(sEluna.L, state);
    sEluna.Push(sEluna.L, unit);
    sEluna.ExecuteCall(4, 0);
}

void HookMgr::OnGameObjectStateChanged(GameObject* gameObject, uint32 state)
{
    int bind = sEluna.GameObjectEventBindings->GetBind(gameObject->GetEntry(), GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED);
    if (!bind)
        return;
    sEluna.BeginCall(bind);
    sEluna.Push(sEluna.L, GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED);
    sEluna.Push(sEluna.L, gameObject);
    sEluna.Push(sEluna.L, state);
    sEluna.ExecuteCall(3, 0);
}
// areatrigger
bool HookMgr::OnAreaTrigger(Player* player, AreaTriggerEntry const* trigger)
{
    for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[TRIGGER_EVENT_ON_TRIGGER].begin();
        itr != sEluna.ServerEventBindings[TRIGGER_EVENT_ON_TRIGGER].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, TRIGGER_EVENT_ON_TRIGGER);
        sEluna.Push(sEluna.L, player);
        sEluna.Push(sEluna.L, trigger->id);
        sEluna.ExecuteCall(3, 0);
    }
    return false;
}
// weather
void HookMgr::OnChange(Weather* weather, WeatherState state, float grade)
{
    for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[WEATHER_EVENT_ON_CHANGE].begin();
        itr != sEluna.ServerEventBindings[WEATHER_EVENT_ON_CHANGE].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, WEATHER_EVENT_ON_CHANGE);
        sEluna.Push(sEluna.L, (weather->GetZone()));
        sEluna.Push(sEluna.L, state);
        sEluna.Push(sEluna.L, grade);
        sEluna.ExecuteCall(4, 0);
    }
}
// transport
void HookMgr::OnAddPassenger(Transport* transport, Player* player)
{
}
void HookMgr::OnAddCreaturePassenger(Transport* transport, Creature* creature)
{
}
void HookMgr::OnRemovePassenger(Transport* transport, Player* player)
{
}
void HookMgr::OnRelocate(Transport* transport, uint32 waypointId, uint32 mapId, float x, float y, float z)
{
}

/*
class Eluna::Eluna_WorldScript : public WorldScript
{
public:
    Eluna_WorldScript() : WorldScript("SmartEluna_WorldScript") { }
    ~Eluna_WorldScript() { }

    void OnOpenStateChange(bool open)
    {
        for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[WORLD_EVENT_ON_OPEN_STATE_CHANGE].begin();
            itr != sEluna.ServerEventBindings[WORLD_EVENT_ON_OPEN_STATE_CHANGE].end(); ++itr)
        {
            sEluna.BeginCall((*itr));
            sEluna.Push(sEluna.L, WORLD_EVENT_ON_OPEN_STATE_CHANGE);
            sEluna.Push(sEluna.L, open);
            sEluna.ExecuteCall(2, 0);
        }
    }

    void OnConfigLoad(bool reload)
    {
        for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[WORLD_EVENT_ON_CONFIG_LOAD].begin();
            itr != sEluna.ServerEventBindings[WORLD_EVENT_ON_CONFIG_LOAD].end(); ++itr)
        {
            sEluna.BeginCall((*itr));
            sEluna.Push(sEluna.L, WORLD_EVENT_ON_CONFIG_LOAD);
            sEluna.Push(sEluna.L, reload);
            sEluna.ExecuteCall(2, 0);
        }
    }

    void OnMotdChange(std::string& newMotd)
    {
        for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[WORLD_EVENT_ON_MOTD_CHANGE].begin();
            itr != sEluna.ServerEventBindings[WORLD_EVENT_ON_MOTD_CHANGE].end(); ++itr)
        {
            sEluna.BeginCall((*itr));
            sEluna.Push(sEluna.L, WORLD_EVENT_ON_MOTD_CHANGE);
            sEluna.Push(sEluna.L, newMotd);
            sEluna.ExecuteCall(2, 0);
        }
    }

    void OnShutdownInitiate(ShutdownExitCode code, ShutdownMask mask)
    {
        for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN_INIT].begin();
            itr != sEluna.ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN_INIT].end(); ++itr)
        {
            sEluna.BeginCall((*itr));
            sEluna.Push(sEluna.L, WORLD_EVENT_ON_SHUTDOWN_INIT);
            sEluna.Push(sEluna.L, code);
            sEluna.Push(sEluna.L, mask);
            sEluna.ExecuteCall(3, 0);
        }
    }

    void OnShutdownCancel()
    {
        for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN_CANCEL].begin();
            itr != sEluna.ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN_CANCEL].end(); ++itr)
        {
            sEluna.BeginCall((*itr));
            sEluna.Push(sEluna.L, WORLD_EVENT_ON_SHUTDOWN_CANCEL);
            sEluna.ExecuteCall(1, 0);
        }
    }

    void OnUpdate(uint32 diff)
    {
        for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[WORLD_EVENT_ON_UPDATE].begin();
            itr != sEluna.ServerEventBindings[WORLD_EVENT_ON_UPDATE].end(); ++itr)
        {
            sEluna.BeginCall((*itr));
            sEluna.Push(sEluna.L, WORLD_EVENT_ON_UPDATE);
            sEluna.Push(sEluna.L, diff);
            sEluna.ExecuteCall(2, 0);
        }
    }
    // executed when a  timed event fires
    void OnScriptEvent(int funcRef, uint32 delay, uint32 calls)
    {
        sEluna.BeginCall(funcRef);
        sEluna.Push(sEluna.L, funcRef);
        sEluna.Push(sEluna.L, delay);
        sEluna.Push(sEluna.L, calls);
        sEluna.ExecuteCall(3, 0);
    }

    void OnStartup()
    {
        for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[WORLD_EVENT_ON_STARTUP].begin();
            itr != sEluna.ServerEventBindings[WORLD_EVENT_ON_STARTUP].end(); ++itr)
        {
            sEluna.BeginCall((*itr));
            sEluna.Push(sEluna.L, WORLD_EVENT_ON_STARTUP);
            sEluna.ExecuteCall(1, 0);
        }
    }

    void OnShutdown()
    {
        for (std::vector<int>::const_iterator itr = sEluna.ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN].begin();
            itr != sEluna.ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN].end(); ++itr)
        {
            sEluna.BeginCall((*itr));
            sEluna.Push(sEluna.L, WORLD_EVENT_ON_SHUTDOWN);
            sEluna.ExecuteCall(1, 0);
        }
    }
};
*/

struct HookMgr::ElunaCreatureAI : public ReactorAI
{
    ElunaCreatureAI(Creature* creature) : ReactorAI(creature) { }
    ~ElunaCreatureAI() { }

    // Called at World update tick
    void UpdateAI(uint32 const diff)
    {
        ReactorAI::UpdateAI(diff);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_AIUPDATE);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_AIUPDATE);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, diff);
        sEluna.ExecuteCall(3, 0);
    }

    // Called for reaction at enter to combat if not in combat yet (enemy can be NULL)
    // Called at creature aggro either by MoveInLOS or Attack Start
    void EnterCombat(Unit* target)
    {
        ReactorAI::EnterCombat(target);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_ENTER_COMBAT);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_ENTER_COMBAT);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, target);
        sEluna.ExecuteCall(3, 0);
    }

    // Called at any Damage from any attacker (before damage apply)
    void DamageTaken(Unit* attacker, uint32& damage)
    {
        ReactorAI::DamageTaken(attacker, damage);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_DAMAGE_TAKEN);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_DAMAGE_TAKEN);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, attacker);
        sEluna.Push(sEluna.L, damage);
        sEluna.ExecuteCall(4, 0);
    }

    // Called at creature death
    void JustDied(Unit* killer)
    {
        ReactorAI::JustDied(killer);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_DIED);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_DIED);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, killer);
        sEluna.ExecuteCall(3, 0);
    }

    // Called at creature killing another unit
    void KilledUnit(Unit* victim)
    {
        ReactorAI::KilledUnit(victim);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_TARGET_DIED);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_TARGET_DIED);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, victim);
        sEluna.ExecuteCall(3, 0);
    }

    // Called when the creature summon successfully other creature
    void JustSummoned(Creature* summon)
    {
        ReactorAI::JustSummoned(summon);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, summon);
        sEluna.ExecuteCall(3, 0);
    }

    // Called when a summoned creature is despawned
    void SummonedCreatureDespawn(Creature* summon)
    {
        ReactorAI::SummonedCreatureDespawn(summon);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, summon);
        sEluna.ExecuteCall(3, 0);
    }

    // Called when hit by a spell
    void SpellHit(Unit* caster, SpellEntry const* spell)
    {
        ReactorAI::SpellHit(caster, spell);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_HIT_BY_SPELL);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_HIT_BY_SPELL);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, caster);
        sEluna.Push(sEluna.L, spell->Id);           // Pass spell object?
        sEluna.ExecuteCall(4, 0);
    }

    // Called when spell hits a target
    void SpellHitTarget(Unit* target, SpellEntry const* spell)
    {
        ReactorAI::SpellHitTarget(target, spell);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_SPELL_HIT_TARGET);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_SPELL_HIT_TARGET);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, target);
        sEluna.Push(sEluna.L, spell->Id);           // Pass spell object?
        sEluna.ExecuteCall(4, 0);
    }

    // Called at waypoint reached or PointMovement end
    void MovementInform(uint32 type, uint32 id)
    {
        ReactorAI::MovementInform(type, id);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_REACH_WP);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_REACH_WP);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, type);
        sEluna.Push(sEluna.L, id);
        sEluna.ExecuteCall(4, 0);
    }

    // Called when AI is temporarily replaced or put back when possess is applied or removed
    /*
    void OnPossess(bool apply)
    {
        ReactorAI::OnPossess(apply);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_POSSESS);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_POSSESS);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, apply);
        sEluna.ExecuteCall(3, 0);
    }*/

    // Called at creature reset either by death or evade
    /*void Reset()
    {
        ReactorAI::Reset();
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_RESET);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_RESET);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.ExecuteCall(2, 0);
    }*/

    // Called before EnterCombat even before the creature is in combat.
    void AttackStart(Unit* target)
    {
        ReactorAI::AttackStart(target);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_PRE_COMBAT);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_PRE_COMBAT);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, target);
        sEluna.ExecuteCall(3, 0);
    }

    // Called in Creature::Update when deathstate = DEAD. Inherited classes may maniuplate the ability to respawn based on scripted events.
    /*
    bool CanRespawn()
    {
        ReactorAI::CanRespawn();
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_CAN_RESPAWN);
        if (!bind)
            return true;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_CAN_RESPAWN);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.ExecuteCall(2, 0);
        return true;
    }*/

    // Called for reaction at stopping attack at no attackers or targets
    void EnterEvadeMode()
    {
        ReactorAI::EnterEvadeMode();
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_LEAVE_COMBAT);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_LEAVE_COMBAT);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.ExecuteCall(2, 0);
    }

    // Called when the creature is summoned successfully by other creature
    /*void IsSummonedBy(Unit* summoner)
    {
        ReactorAI::IsSummonedBy(summoner);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_SUMMONED);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_SUMMONED);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, summoner);
        sEluna.ExecuteCall(3, 0);
    }*/

    /*void SummonedCreatureDies(Creature* summon, Unit* killer)
    {
        ReactorAI::SummonedCreatureDies(summon, killer);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, summon);
        sEluna.Push(sEluna.L, killer);
        sEluna.ExecuteCall(4, 0);
    }*/

    // Called when the creature is target of hostile action: swing, hostile spell landed, fear/etc)
    void AttackedBy(Unit* attacker)
    {
        ReactorAI::AttackedBy(attacker);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_ATTACKED_AT);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_ATTACKED_AT);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, attacker);
        sEluna.ExecuteCall(3, 0);
    }

    // Called when creature is spawned or respawned (for reseting variables)
    void JustRespawned()
    {
        ReactorAI::JustRespawned();
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_SPAWN);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_SPAWN);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.ExecuteCall(2, 0);
    }

    /*void OnCharmed(bool apply)
    {
        ReactorAI::OnCharmed(apply);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_CHARMED);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_CHARMED);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, apply);
        sEluna.ExecuteCall(3, 0);
    }*/

    // Called at reaching home after evade
    void JustReachedHome()
    {
        ReactorAI::JustReachedHome();
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_REACH_HOME);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_REACH_HOME);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.ExecuteCall(2, 0);
    }

    // Called at text emote receive from player
    void ReceiveEmote(Player* player, uint32 emoteId)
    {
        ReactorAI::ReceiveEmote(player, emoteId);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_RECEIVE_EMOTE);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_RECEIVE_EMOTE);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, player);
        sEluna.Push(sEluna.L, emoteId);
        sEluna.ExecuteCall(4, 0);
    }

    // Called when owner takes damage
    /*void OwnerAttackedBy(Unit* attacker)
    {
        ReactorAI::OwnerAttackedBy(attacker);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, attacker);
        sEluna.ExecuteCall(3, 0);
    }*/

    // Called when owner attacks something
    /*void OwnerAttacked(Unit* target)
    {
        ReactorAI::OwnerAttacked(target);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_OWNER_ATTACKED);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_OWNER_ATTACKED);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, target);
        sEluna.ExecuteCall(3, 0);
    }*/

    // called when the corpse of this creature gets removed
    void CorpseRemoved(uint32& respawnDelay)
    {
        ReactorAI::CorpseRemoved(respawnDelay);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_CORPSE_REMOVED);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_CORPSE_REMOVED);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, respawnDelay);
        sEluna.ExecuteCall(3, 0);
    }

    /*void PassengerBoarded(Unit* assenger, int8 seatId, bool apply)
    {
        ReactorAI::PassengerBoarded(passenger, seatId, apply);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_PASSANGER_BOARDED);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_PASSANGER_BOARDED);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, passenger);
        sEluna.Push(sEluna.L, seatId);
        sEluna.Push(sEluna.L, apply);
        sEluna.ExecuteCall(5, 0);
    }*/

    /*void OnSpellClick(Unit* clicker, bool& result)
    {
        ReactorAI::OnSpellClick(clicker, result);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_SPELL_CLICK);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_SPELL_CLICK);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, clicker);
        sEluna.Push(sEluna.L, result);
        sEluna.ExecuteCall(4, 0);
    }*/

    void MoveInLineOfSight(Unit* who)
    {
        ReactorAI::MoveInLineOfSight(who);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_MOVE_IN_LOS);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_MOVE_IN_LOS);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, who);
        sEluna.ExecuteCall(3, 0);
    }

    // Called if IsVisible(Unit* who) is true at each who move, reaction at visibility zone enter
    /*void MoveInLineOfSight_Safe(Unit* who)
    {
        ReactorAI::MoveInLineOfSight_Safe(who);
        int bind = sEluna.CreatureEventBindings->GetBind(m_creature->GetEntry(), CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
        sEluna.Push(sEluna.L, m_creature);
        sEluna.Push(sEluna.L, who);
        sEluna.ExecuteCall(3, 0);
    }*/
};

struct HookMgr::ElunaGameObjectAI : public GameObjectAI
{
    ElunaGameObjectAI(GameObject* _go) : GameObjectAI(_go) { }
    ~ElunaGameObjectAI()
    {
    }

    void UpdateAI(uint32 const diff)
    {
        int bind = sEluna.GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_AIUPDATE);
        if (!bind)
            return;
        sEluna.BeginCall(bind);
        sEluna.Push(sEluna.L, GAMEOBJECT_EVENT_ON_AIUPDATE);
        sEluna.Push(sEluna.L, go);
        sEluna.Push(sEluna.L, diff);
        sEluna.ExecuteCall(3, 0);
    }

    // executed when a timed event fires
    void OnScriptEvent(int funcRef, uint32 delay, uint32 calls)
    {
        sEluna.BeginCall(funcRef);
        sEluna.Push(sEluna.L, funcRef);
        sEluna.Push(sEluna.L, delay);
        sEluna.Push(sEluna.L, calls);
        sEluna.Push(sEluna.L, go);
        sEluna.ExecuteCall(4, 0);
    }

    void Reset()
    {
        sEluna.BeginCall(sEluna.GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_RESET));
        sEluna.Push(sEluna.L, GAMEOBJECT_EVENT_ON_RESET);
        sEluna.Push(sEluna.L, go);
        sEluna.ExecuteCall(2, 0);
    }
};

void HookMgr::OnAddMember(Guild* guild, Player* player, uint32 plRank)
{
    for (std::vector<int>::const_iterator itr = sEluna.GuildEventBindings[GUILD_EVENT_ON_ADD_MEMBER].begin();
        itr != sEluna.GuildEventBindings[GUILD_EVENT_ON_ADD_MEMBER].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, GUILD_EVENT_ON_ADD_MEMBER);
        sEluna.Push(sEluna.L, guild);
        sEluna.Push(sEluna.L, player);
        sEluna.Push(sEluna.L, plRank);
        sEluna.ExecuteCall(4, 0);
    }
}

void HookMgr::OnRemoveMember(Guild* guild, Player* player, bool isDisbanding, bool isKicked) // IsKicked not a part of Mangos, implement?
{
    for (std::vector<int>::const_iterator itr = sEluna.GuildEventBindings[GUILD_EVENT_ON_REMOVE_MEMBER].begin();
        itr != sEluna.GuildEventBindings[GUILD_EVENT_ON_REMOVE_MEMBER].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, GUILD_EVENT_ON_REMOVE_MEMBER);
        sEluna.Push(sEluna.L, guild);
        sEluna.Push(sEluna.L, player);
        sEluna.Push(sEluna.L, isDisbanding);
        sEluna.Push(sEluna.L, isKicked); // IsKicked not a part of Mangos, implement?
        sEluna.ExecuteCall(5, 0);
    }
}

void HookMgr::OnMOTDChanged(Guild* guild, const std::string& newMotd)
{
    for (std::vector<int>::const_iterator itr = sEluna.GuildEventBindings[GUILD_EVENT_ON_MOTD_CHANGE].begin();
        itr != sEluna.GuildEventBindings[GUILD_EVENT_ON_MOTD_CHANGE].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, GUILD_EVENT_ON_MOTD_CHANGE);
        sEluna.Push(sEluna.L, guild);
        sEluna.Push(sEluna.L, newMotd);
        sEluna.ExecuteCall(3, 0);
    }
}

void HookMgr::OnInfoChanged(Guild* guild, const std::string& newInfo)
{
    for (std::vector<int>::const_iterator itr = sEluna.GuildEventBindings[GUILD_EVENT_ON_INFO_CHANGE].begin();
        itr != sEluna.GuildEventBindings[GUILD_EVENT_ON_INFO_CHANGE].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, GUILD_EVENT_ON_INFO_CHANGE);
        sEluna.Push(sEluna.L, guild);
        sEluna.Push(sEluna.L, newInfo);
        sEluna.ExecuteCall(3, 0);
    }
}

void HookMgr::OnCreate(Guild* guild, Player* leader, const std::string& name)
{
    for (std::vector<int>::const_iterator itr = sEluna.GuildEventBindings[GUILD_EVENT_ON_CREATE].begin();
        itr != sEluna.GuildEventBindings[GUILD_EVENT_ON_CREATE].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, GUILD_EVENT_ON_CREATE);
        sEluna.Push(sEluna.L, guild);
        sEluna.Push(sEluna.L, leader);
        sEluna.Push(sEluna.L, name);
        sEluna.ExecuteCall(4, 0);
    }
}

void HookMgr::OnDisband(Guild* guild)
{
    for (std::vector<int>::const_iterator itr = sEluna.GuildEventBindings[GUILD_EVENT_ON_DISBAND].begin();
        itr != sEluna.GuildEventBindings[GUILD_EVENT_ON_DISBAND].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, GUILD_EVENT_ON_DISBAND);
        sEluna.Push(sEluna.L, guild);
        sEluna.ExecuteCall(2, 0);
    }
}

void HookMgr::OnMemberWitdrawMoney(Guild* guild, Player* player, uint32 &amount, bool isRepair) // isRepair not a part of Mangos, implement?
{
    for (std::vector<int>::const_iterator itr = sEluna.GuildEventBindings[GUILD_EVENT_ON_MONEY_WITHDRAW].begin();
        itr != sEluna.GuildEventBindings[GUILD_EVENT_ON_MONEY_WITHDRAW].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, GUILD_EVENT_ON_MONEY_WITHDRAW);
        sEluna.Push(sEluna.L, guild);
        sEluna.Push(sEluna.L, player);
        sEluna.Push(sEluna.L, amount);
        sEluna.Push(sEluna.L, isRepair); // isRepair not a part of Mangos, implement?
        sEluna.ExecuteCall(5, 0);
    }
}

void HookMgr::OnMemberDepositMoney(Guild* guild, Player* player, uint32 &amount)
{
    for (std::vector<int>::const_iterator itr = sEluna.GuildEventBindings[GUILD_EVENT_ON_MONEY_DEPOSIT].begin();
        itr != sEluna.GuildEventBindings[GUILD_EVENT_ON_MONEY_DEPOSIT].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, GUILD_EVENT_ON_MONEY_DEPOSIT);
        sEluna.Push(sEluna.L, guild);
        sEluna.Push(sEluna.L, player);
        sEluna.Push(sEluna.L, amount);
        sEluna.ExecuteCall(4, 0);
    }
}

void HookMgr::OnItemMove(Guild* guild, Player* player, Item* item, bool isSrcBank, uint8 srcContainer, uint8 srcSlotId,
                bool isDestBank, uint8 destContainer, uint8 destSlotId)
{
    for (std::vector<int>::const_iterator itr = sEluna.GuildEventBindings[GUILD_EVENT_ON_ITEM_MOVE].begin();
        itr != sEluna.GuildEventBindings[GUILD_EVENT_ON_ITEM_MOVE].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, GUILD_EVENT_ON_ITEM_MOVE);
        sEluna.Push(sEluna.L, guild);
        sEluna.Push(sEluna.L, player);
        sEluna.Push(sEluna.L, item);
        sEluna.Push(sEluna.L, isSrcBank);
        sEluna.Push(sEluna.L, srcContainer);
        sEluna.Push(sEluna.L, srcSlotId);
        sEluna.Push(sEluna.L, isDestBank);
        sEluna.Push(sEluna.L, destContainer);
        sEluna.Push(sEluna.L, destSlotId);
        sEluna.ExecuteCall(10, 0);
    }
}

void HookMgr::OnEvent(Guild* guild, uint8 eventType, uint32 playerGuid1, uint32 playerGuid2, uint8 newRank)
{
    for (std::vector<int>::const_iterator itr = sEluna.GuildEventBindings[GUILD_EVENT_ON_EVENT].begin();
        itr != sEluna.GuildEventBindings[GUILD_EVENT_ON_EVENT].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, GUILD_EVENT_ON_EVENT);
        sEluna.Push(sEluna.L, guild);
        sEluna.Push(sEluna.L, eventType);
        sEluna.Push(sEluna.L, playerGuid1);
        sEluna.Push(sEluna.L, playerGuid2);
        sEluna.Push(sEluna.L, newRank);
        sEluna.ExecuteCall(6, 0);
    }
}

void HookMgr::OnBankEvent(Guild* guild, uint8 eventType, uint8 tabId, uint32 playerGuid, uint32 itemOrMoney, uint16 itemStackCount, uint8 destTabId)
{
    for (std::vector<int>::const_iterator itr = sEluna.GuildEventBindings[GUILD_EVENT_ON_BANK_EVENT].begin();
        itr != sEluna.GuildEventBindings[GUILD_EVENT_ON_BANK_EVENT].end(); ++itr)
    {
        sEluna.BeginCall((*itr));
        sEluna.Push(sEluna.L, GUILD_EVENT_ON_BANK_EVENT);
        sEluna.Push(sEluna.L, guild);
        sEluna.Push(sEluna.L, eventType);
        sEluna.Push(sEluna.L, tabId);
        sEluna.Push(sEluna.L, playerGuid);
        sEluna.Push(sEluna.L, itemOrMoney);
        sEluna.Push(sEluna.L, itemStackCount);
        sEluna.Push(sEluna.L, destTabId);
        sEluna.ExecuteCall(8, 0);
    }
}

CreatureAI* HookMgr::GetAI(Creature* creature)
{
    if (!sEluna.CreatureEventBindings->GetBindMap(creature->GetEntry()))
        return NULL;
    return new ElunaCreatureAI(creature);
}
GameObjectAI* HookMgr::GetAI(GameObject* gameObject)
{
    if (!sEluna.GameObjectEventBindings->GetBindMap(gameObject->GetEntry()))
        return NULL;
    return new ElunaGameObjectAI(gameObject);
}

void AddElunaScripts()
{
    new ElunaPlayerScript();
    new ElunaGroupScript();
}