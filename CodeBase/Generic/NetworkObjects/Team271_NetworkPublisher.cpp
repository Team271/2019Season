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

Team271NetworkPublisher::Team271NetworkPublisher( const string& argName,
                                                  const string& argAddrPubSync,
                                                  const string& argAddrPub )
      : Name_( argName ),
        AddrSync_( argAddrPubSync ),
        Addr_( argAddrPub ),
        Sync_( ZMQContext_,
                  socket_type::rep ),
        Socket_( ZMQContext_,
              socket_type::pub )

{
   uint32_t tmpLINGER = 0;

   /*
    * Setup ZMQ Pub Sync
    */
   Sync_.setsockopt( ZMQ_SNDHWM,
                        &SyncSNDHWM_,
                        sizeof( SyncSNDHWM_ ) );

   Sync_.setsockopt( ZMQ_LINGER,
                        &tmpLINGER,
                        sizeof( tmpLINGER ) );

   Sync_.bind( AddrSync_ );

   /*
    * Setup ZMQ Pub
    */
   Socket_.setsockopt( ZMQ_SNDHWM,
                    &SNDHWM_,
                    sizeof( SNDHWM_ ) );

   Socket_.setsockopt( ZMQ_LINGER,
                    &tmpLINGER,
                    sizeof( tmpLINGER ) );

   Socket_.bind( Addr_ );
}

Team271NetworkPublisher::~Team271NetworkPublisher( void )
{
   /*
    * ZMQ Pub
    */
   Socket_.unbind( Addr_ );

   Socket_.close();

   /*
    * ZMQ Pub Sync
    */
   if( Sync_.connected() == true )
   {
      multipart_t tmpMsgSend;

      tmpMsgSend.addstr( "End" );

      /*
       * Send the Message
       */
      tmpMsgSend.send( Sync_ );
   }

   Sync_.unbind( AddrSync_ );

   Sync_.close();
}

/*
 *
 * Getters
 *
 */
const string Team271NetworkPublisher::GetClassName( void ) const
{
   return "Team271NetworkPublisher";
}

const string& Team271NetworkPublisher::GetName( void ) const
{
   return Name_;
}

socket_t& Team271NetworkPublisher::GetSocket( void )
{
   return Socket_;
}

uint32_t Team271NetworkPublisher::GetConnected( void ) const
{
   return (uint32_t)( ( SyncConnected_ == 1U ) && ( Connected_ == 1U ) );
}

uint32_t Team271NetworkPublisher::GetDirty( void ) const
{
   uint8_t tmpHasDirty = 0;

   return tmpHasDirty;
}

uint32_t Team271NetworkPublisher::GetDirty( const uint32_t argIndex ) const
{
   uint8_t tmpHasDirty = 0;

   return tmpHasDirty;
}

/*
 *
 * Setters
 *
 */
void Team271NetworkPublisher::SetName( const string& argName )
{

}

void Team271NetworkPublisher::SetDirty( void )
{

}

void Team271NetworkPublisher::ClearDirty( void )
{

}

/*
 *
 * Publisher
 *
 */
void Team271NetworkPublisher::PubLoop( void )
{
   uint8_t tmpForceDirty = 0;

   SyncConnectedPrev_ = SyncConnected_;
   ConnectedPrev_ = Connected_;

   /*
    *
    * Check Sync Port
    *
    */
   if( Sync_.connected() == true )
   {
      /*
       * Check if we've Received Data
       */
      multipart_t tmpMsgRecv;

      if( tmpMsgRecv.recv( Sync_,
                           ZMQ_DONTWAIT ) == true )
      {
         const string tmpData = tmpMsgRecv.popstr();

         /*
          * Check the Data in the Message
          * If it's ever a Start Sync then Start/Restart the Connection Process
          */
         if( tmpData == "Start" )
         {
            /*
             * Send A Message Back
             */
            multipart_t tmpMsgSend;

            tmpMsgSend.addstr( "Team271" );

            tmpMsgSend.send( Sync_ );

            SyncConnected_ = 1U;
            Connected_ = 0;

            tmpForceDirty = 1;

            TimeLastPubSync = Team271Robot::GetTime();

            LOG_NOTICE( "%s - Received Start Sync",
                        GetName().c_str() );
         }
         else if( tmpData == "End" )
         {
            multipart_t tmpMsgSend;

            tmpMsgSend.addstr( "Team271" );

            tmpMsgSend.send( Sync_ );

            LOG_NOTICE( "%s - Received End",
                        GetName().c_str() );

            SyncConnected_ = 0U;
            Connected_ = 0U;
         }
         else
         {
            LOG_NOTICE( "%s - Received Start Sync Error",
                        GetName().c_str() );

            SyncConnected_ = 0U;
            Connected_ = 0U;
         }
      }
   }

   if( ( SyncConnected_ != SyncConnectedPrev_ ) && ( SyncConnected_ == 0U ) )
   {
      LOG_NOTICE( "%s - Sync Disconnect",
                  GetName().c_str() );

      SyncConnected_ = 0U;
      Connected_ = 0U;
   }

   /*
    * Check if we should Resync All Data
    * - Be careful as this is A LOT of data
    */
   if( ( ( Connected_ != ConnectedPrev_ ) && ( Connected_ == 0 ) ) || ( tmpForceDirty == 1 ) )
   {
      SetDirty();
   }

   /*
    *
    * If we've received a Sync Start then start Publishing Data
    *
    */
   if( SyncConnected_ == 1U )
   {
      if( Socket_.connected() == true )
      {
         /*
          * Set Connected
          */
         Connected_ = 1;

         if( Connected_ != ConnectedPrev_ )
         {
            LOG_NOTICE( "%s - Pub Connected",
                        GetName().c_str() );
         }

         /*
          * Publish Data
          */
         Pub();

         /*
          * Update Loop Count
          */
         ++NetworkMessageLoopCount_;
      }
      else
      {
         if( Connected_ != ConnectedPrev_ )
         {
            LOG_NOTICE( "%s - Pub Disconnect",
                        GetName().c_str() );
         }

         Connected_ = 0;
      }
   }
   else
   {
      if( Connected_ != ConnectedPrev_ )
      {
         LOG_NOTICE( "%s - Pub Disconnect",
                     GetName().c_str() );
      }

      Connected_ = 0;
   }
}

void Team271NetworkPublisher::Pub( void )
{

}
