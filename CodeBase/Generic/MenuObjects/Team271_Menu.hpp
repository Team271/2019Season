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

#ifndef TEAM271_MENU_H_
#define TEAM271_MENU_H_

#define T271_MENU_MAX_CHILDREN   (8U)

class t271_menu_data_index : public t271_network_data_index
{
public:
   typedef enum : uint8_t
   {
      T271_MENU_DATA_CHILDREN = t271_network_data_index::T271_DATA_COUNT,

      T271_DATA_COUNT,
   } t271_menu_data_index_t;
};

class Team271Menu : public Team271NetworkObject
{
protected:
   Team271Menu* Parent_ = nullptr;
   Team271Menu* Children_[T271_MENU_MAX_CHILDREN];

public:
   /*
    *
    * Constructor/Destructor
    *
    */

   Team271Menu(Team271Menu* const argParent = nullptr,
               const string& argName = "",
               const uint8_t argMessageCount = t271_menu_data_index::T271_DATA_COUNT);

   virtual ~Team271Menu( void );

   /*
    *
    * Getters
    *
    */
   const string GetClassName(void) const override;

   Team271Menu* GetParent(void) const;

   const string GetPath(void) const;

   const string GetPath(const string& argClassName) const;

   uint32_t GetDirty(void) const override;

   uint32_t GetDirtyString(const uint32_t argIndex) const override;

   uint32_t GetDirty(const uint32_t argIndex) const override;

   /*
    *
    * Setters
    *
    */
   void SetParent(Team271Menu* const argParent);

   void SetDirty(void) override;

   void ClearDirty(void) override;

   /*
    *
    * Base
    *
    */
   virtual void Init(void);

   /*
    *
    * Child Functions
    *
    */
   int32_t ChildAdd(Team271Menu* const argChild);
};

#endif /* TEAM271_MENU_H_ */
