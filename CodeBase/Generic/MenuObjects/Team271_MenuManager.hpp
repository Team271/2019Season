/*
 *    FRC Team 271's 2019 Comp Season Code
 *    Copyright (C) 2019  FRC Team 271
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef TEAM271_MENU_MANAGER_H_
#define TEAM271_MENU_MANAGER_H_

#define T271_MENU_MANAGER_START_INDEX   (T271_NETWORK_OBJECT_NETWORK_ID_END)
#define T271_MENU_MANAGER_MAX_OBJECTS   (255U - T271_MENU_MANAGER_START_INDEX)

/*
 *
 * Shared Network Data
 *
 */
class t271_menu_manager_data_index : public t271_network_data_index
{
public:
   typedef enum : uint8_t
   {
      T271_MENU_MANAGER_DATA_OBJECT_COUNT = t271_network_data_index::T271_DATA_COUNT,

      T271_DATA_COUNT,
   } t271_menu_manager_data_index_t;
};

class Team271MenuManager : public Team271NetworkObject
{
protected:
   /*
    *
    * Variables
    *
    */
   uint8_t ObjCount_ = 0;
   Team271Menu* Objs_[T271_MENU_MANAGER_MAX_OBJECTS];

public:
   static Team271MenuManager& Instance(void);

   template<typename T>
   static T InstanceAdd(T const argObj)
   {
      return (T)Instance().Add(argObj);
   }

   static void InstanceCreateMessages(Team271NetworkPublisher& argPublisher,
                                      const float argTimeStamp);

   static void InstanceDecodeMessages(multipart_t& argMessage);

   /*
    *
    * Constructor/Destructor
    *
    */
   Team271MenuManager(void);

   virtual ~Team271MenuManager(void);

   Team271MenuManager(Team271MenuManager const&) = delete;
   void operator=(Team271MenuManager const&) = delete;

   /*
    *
    * Getters
    *
    */
   Team271Menu* GetByName(const string& argName) const;

   Team271Menu* GetByPath(const string& argName) const;

   Team271Menu* GetByPath(const string& argName,
                          const string& argClassName) const;

   /*
    *
    * Child Functions
    *
    */
   Team271Menu* Add(Team271Menu* const argObj);

   /*
    *
    * Network
    *
    */
   void CreateMessages(Team271NetworkPublisher& argPublisher,
                       const float argTimeStamp);

   void DecodeMessages(multipart_t& argMessage);
};

#endif /* TEAM271_MENU_MANAGER_H_ */
