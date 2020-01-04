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

#include "Team271_Includes.hpp"

Team271Menu::Team271Menu(Team271Menu* const argParent,
                         const string& argName,
                         const uint8_t argMessageCount)
      : Team271NetworkObject(argName,
                             argMessageCount)

{
#if defined( ENABLE_DEBUG_PRINTING_TRACE )
   if( Parent_ == nullptr )
   {
      DEBUG_PRINT(GetClassName().c_str(),
                  "Constructor");
   }
   else
   {
      DEBUG_PRINT(GetClassName().c_str(),
                  "Constructor - Parent: %s",
                  Parent_->GetName());
   }
#endif

   /*
    * Clear Out Children
    */
   for (uint8_t i = 0; i < T271_MENU_MAX_CHILDREN; i++)
   {
      Children_[i] = nullptr;
   }

   if (argParent != nullptr)
   {
      argParent->ChildAdd(this);
   }
}

Team271Menu::~Team271Menu(void)
{
#if 0
   /*
    * Delete Children
    */
   for( uint8_t i = 0; i < T271_MENU_MAX_CHILDREN; i++ )
   {
      if( Children_[i] != nullptr )
      {
         delete Children_[i];
      }

      Children_[i] = nullptr;
   }
#endif
}

/*
 *
 * Getters
 *
 */
const string Team271Menu::GetClassName(void) const
{
   return "Team271Menu";
}

Team271Menu* Team271Menu::GetParent(void) const
{
   return Parent_;
}

const string Team271Menu::GetPath(void) const
{
   return GetPath(GetClassName());
}

const string Team271Menu::GetPath(const string& argClassName) const
{
   string tmpPath = "(" + GetClassName() + ")" + GetName();
   const Team271Menu* tmpOwner = GetParent();

   while (tmpOwner != nullptr)
   {
      tmpPath.insert(0,
                     "(" + tmpOwner->GetClassName() + ")" + tmpOwner->GetName() + "/");

      tmpOwner = tmpOwner->GetParent();
   }

   return tmpPath;
}

uint32_t Team271Menu::GetDirty(void) const
{
   /*
    * Base Call
    */
   uint8_t tmpDirty = Team271NetworkObject::GetDirty();

   /*
    * Update Children
    */
   for (uint8_t i = 0; i < T271_MENU_MAX_CHILDREN; i++)
   {
      if (( Children_[i] != nullptr ) && ( Children_[i]->GetDirty() == 1 ))
      {
         tmpDirty = 1U;
         break;
      }
   }

   return tmpDirty;
}

uint32_t Team271Menu::GetDirtyString(const uint32_t argIndex) const
{
   /*
    * Base Call
    */
   uint8_t tmpDirty = Team271NetworkObject::GetDirtyString(argIndex);

   /*
    * Update Children
    */
   /*
    for( uint8_t i = 0; i < T271_MENU_MAX_CHILDREN; i++ )
    {
    if( (Children_[i] != nullptr) && (Children_[i]->GetDirtyString( argIndex ) == 1) )
    {
    tmpDirty = 1U;
    break;
    }
    }
    */
   return tmpDirty;
}

uint32_t Team271Menu::GetDirty(const uint32_t argIndex) const
{
   /*
    * Base Call
    */
   uint8_t tmpDirty = Team271NetworkObject::GetDirty(argIndex);

   /*
    * Update Children
    */
   /*
    for( uint8_t i = 0; i < T271_MENU_MAX_CHILDREN; i++ )
    {
    if( (Children_[i] != nullptr) && (Children_[i]->GetDirty( argIndex ) == 1) )
    {
    tmpDirty = 1U;
    break;
    }
    }
    */
   return tmpDirty;
}

/*
 *
 * Setters
 *
 */
void Team271Menu::SetParent(Team271Menu* const argParent)
{
   Parent_ = argParent;
}

void Team271Menu::SetDirty(void)
{
   /*
    * Base Call
    */
   Team271NetworkObject::SetDirty();

   /*
    * Update Children
    */
   for (uint8_t i = 0; i < T271_MENU_MAX_CHILDREN; i++)
   {
      if (Children_[i] != nullptr)
      {
         Children_[i]->SetDirty();
      }
   }
}

void Team271Menu::ClearDirty(void)
{
   /*
    * Base Call
    */
   Team271NetworkObject::ClearDirty();

   /*
    * Update Children
    */
   for (uint8_t i = 0; i < T271_MENU_MAX_CHILDREN; i++)
   {
      if (Children_[i] != nullptr)
      {
         Children_[i]->ClearDirty();
      }
   }
}

/*
 *
 * Base
 *
 */
void Team271Menu::Init(void)
{
   /*
    * Update Children
    */
   for (uint8_t i = 0; i < T271_MENU_MAX_CHILDREN; i++)
   {
      if (Children_[i] != nullptr)
      {
         Children_[i]->Init();
      }
   }
}

/*
 *
 * Child Functions
 *
 */
int32_t Team271Menu::ChildAdd(Team271Menu* const argChild)
{
   uint8_t i = 0;
   uint8_t tmpIndex = -1;

   if (argChild == nullptr)
   {
      LOG_ERROR("Invalid Child - Parent: %s",
                GetName().c_str());
   }
   else if (argChild->GetParent() != nullptr)
   {
      LOG_ERROR("Child Already Has Owner - Child: %s | New Parent: %s | Existing Parent: %s",
                argChild->GetName().c_str(),
                GetName().c_str(),
                argChild->GetParent()->GetName().c_str());
   }
   else
   {
      /*
       * Find Free Child Slot
       */
      for (i = 0; i < T271_MENU_MAX_CHILDREN; i++)
      {
         /*
          * Check if the Child Node is free
          */
         if (Children_[i] == nullptr)
         {
            /*
             * Add Child
             */
            Children_[i] = argChild;

            IncUInt32(t271_base_data_index::T271_BASE_DATA_CHILDREN);

            /*
             * Set the Child's Owner
             */
            Children_[i]->SetParent(this);

            /*
             * Store Index to Return
             */
            tmpIndex = i;

            /*
             * Break Out of the Loop
             */
            break;
         }
      }

      if (i >= T271_MENU_MAX_CHILDREN)
      {
         /*
          * Log Data
          */
         LOG_ERROR("Max Children Reached - Parent: %s | Child: %s",
                   GetName().c_str(),
                   argChild->GetName().c_str());
      }
   }

   return tmpIndex;
}
