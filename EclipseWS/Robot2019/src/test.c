#ifndef RT_DEMO_MENU_H_
#define RT_DEMO_MENU_H_

/*-----------------------------------------------------------------------------
 *                              Include Files
 *----------------------------------------------------------------------------*/

#include <stdint.h>

/*-----------------------------------------------------------------------------
 *                        Enumerations and Structures
 *----------------------------------------------------------------------------*/

typedef struct
{
   const char* name; /* What to display on the menu */
   void (*func)(void*,
                void*); /* Function to call when item is selected */
   void* arg1; /* Argument 1 to the function */
   void* arg2; /* Argument 2 to the function */
} menu_item_t;

typedef struct
{
   const char* title; /* Title to display at the top of the menu */
   int32_t length; /* How big the menu is in terms of items */
   int32_t lastEntry; /* Where the last entry lives*/
   menu_item_t* items; /* Items in the menu */
} menu_list_t;

/*-----------------------------------------------------------------------------
 *                        Public (Exportable) Functions
 *----------------------------------------------------------------------------*/

int32_t menu_option_register(const char* name,
                             void (*p_func)(void*,
                                            void*),
                             void* arg1,
                             void* arg2,
                             menu_list_t* p_menu);
int32_t menu_init(const char* title,
                  menu_list_t* p_menu,
                  menu_item_t* p_items,
                  uint32_t len);
int32_t menu_run(menu_list_t* p_menu);

#endif /* RT_DEMO_MENU_H_ */

/* General */
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <stdio.h>
#include <sys/select.h>
/*
// cc.byexamples.com calls this int kbhit(), to mirror the Windows console
//  function of the same name.  Otherwise, the code is the same.
bool inputAvailable()
{
   struct timeval tv;
   fd_set fds;
   tv.tv_sec = 0;
   tv.tv_usec = 0;
   FD_ZERO(&fds);
   FD_SET(STDIN_FILENO,
          &fds);
   select(STDIN_FILENO + 1,
          &fds,
          NULL,
          NULL,
          &tv);
   return ( FD_ISSET(0,
                     &fds) );
}
*/
uint32_t menu_get_print_size(menu_list_t* p_menu);
void menu_print_padding(const char* ch,
                        uint32_t len);

/*-----------------------------------------------------------------------------
 *                               Definitions
 *----------------------------------------------------------------------------*/

#define MENU_TL_CORNER "+"
#define MENU_TR_CORNER "+"
#define MENU_BL_CORNER "+"
#define MENU_BR_CORNER "+"
#define MENU_MIDDLE "+"
#define MENU_VERT   "|"
#define MENU_HORZ   "-"

/*-----------------------------------------------------------------------------
 *                       Public (Exportable) Functions
 *----------------------------------------------------------------------------*/

/******************************************************************************/
/**
 * <summary>
 * Initialize a menu.
 * </summary>
 *
 * @param[in]     title    Title of the menu to be displayed
 * @param[inout]  p_menu   Pointer to menu to initialize
 * @param[in]     p_items  Pointer to item list array
 * @param[in]     len      Length of item list array
 *
 * @returns -1    Menu could not be initailized
 * @returns  0    Menu successfully initialized
 */
/******************************************************************************/
int32_t menu_init(const char* title,
                  menu_list_t* p_menu,
                  menu_item_t* p_items,
                  uint32_t len)
{
   int32_t retVal = 0;
   /* Check for null pointers */
   if (( NULL == p_menu ) || ( NULL == p_items ) || ( NULL == title ))
   {
      retVal = -1;
   }
   else
   {
      p_menu->title = title;
      p_menu->length = len;
      p_menu->lastEntry = -1; /* This is set to -1 to denote an empy list */
      p_menu->items = p_items;
   }
   return retVal;
}

/******************************************************************************/
/**
 * <summary>
 * Register a menu option in a menu
 * </summary>
 *
 * @param[in]     name   What to display in the menu
 * @param[in]     p_func Function pointer
 * @param[inout]  p_menu Pointer to the menu struct array
 *
 * @return -1  Menu Full, can't add
 * @return  n  Where n is the menu item number
 */
/******************************************************************************/
int32_t menu_option_register(const char* name,
                             void (*p_func)(void*,
                                            void*),
                             void* arg1,
                             void* arg2,
                             menu_list_t* p_menu)
{
   int32_t retVal;
   /* Check for null pointers */
   if (( NULL == p_menu ) || ( NULL == name ))
   {
      retVal = -1;
   }
   /* Check to make sure we can fit this in the menu */
   else if (p_menu->length == ( p_menu->lastEntry - 1 ))
   {
      retVal = -1; /* Can't fit any more items */
   }
   else
   {
      p_menu->lastEntry++;
      p_menu->items[p_menu->lastEntry].name = name;
      p_menu->items[p_menu->lastEntry].func = p_func;
      p_menu->items[p_menu->lastEntry].arg1 = arg1;
      p_menu->items[p_menu->lastEntry].arg2 = arg2;
      retVal = p_menu->lastEntry;
   }
   return retVal;
}

/******************************************************************************/
/**
 * <summary>
 * Print a menu out.
 * </summary>
 *
 * @param[in]  p_menu Pointer to the menu struct array
 *
 * @return -1  Menu is empty, does not exist, or is too large to print
 * @return  0  Menu printed successfully to output device
 */
/******************************************************************************/
int32_t menu_print(menu_list_t* p_menu)
{
   int32_t retVal = 0, i;
   uint32_t sz, len;
   /* Check for null pointer */
   if (NULL == p_menu)
   {
      retVal = -1;
   }
   /* Why 80? That's how many columns in a standard screen */
   if (( retVal == 0 ) && ( 80 > menu_get_print_size(p_menu) ))
   {
      sz = menu_get_print_size(p_menu);
      /* We don't care about the borders */
      sz -= 2;

      /* Top Border */
      printf(MENU_TL_CORNER);
      menu_print_padding(MENU_HORZ,
                         ( sz ));
      printf(MENU_TR_CORNER);
      printf("\n");

      /* Title */
      len = strlen(p_menu->title);
      printf(MENU_VERT);
      menu_print_padding(" ",
                         ( ( sz - len ) / 2 ));
      printf(p_menu->title);
      menu_print_padding(" ",
                         ( ( sz - len ) / 2 ));
      /* Off by 1 fix */
      if (( ( ( sz - len ) / 2 ) * 2 ) != ( sz - len ))
      {
         printf(" ");
      }
      printf(MENU_VERT);
      printf("\n");

      /* Title Separator */
      printf(MENU_MIDDLE);
      menu_print_padding(MENU_HORZ,
                         sz);
      printf(MENU_MIDDLE);
      printf("\n");

      /* Menu Items */
      for (i = 0; i <= p_menu->lastEntry; i++)
      {
         printf(MENU_VERT);
         if (10 > p_menu->lastEntry)
         {
            len = 4;
            /* Print the number left justified, with only 1 space for the number */
            printf(" %-1d) ",
                   ( i + 1 ));
         }
         else
         {
            /* Print the number left justified, with 2 spaces for the number */
            len = 5;
            printf(" %-2d) ",
                   ( i + 1 ));
         }
         printf(p_menu->items[i].name);
         len += strlen(p_menu->items[i].name);

         menu_print_padding(" ",
                            ( sz - len ));
         printf(MENU_VERT);
         printf("\n");
      }

      /* Whitespace before End*/
      printf(MENU_VERT);
      menu_print_padding(" ",
                         sz);
      printf(MENU_VERT);
      printf("\n");

      /* End Menu option */
      printf(MENU_VERT);
      if (10 > p_menu->lastEntry)
      {
         len = 8;
         /* Print the number left justified, with only 1 space for the number */
         printf(" %-1d) ",
                0);
      }
      else
      {
         /* Print the number left justified, with 2 spaces for the number */
         len = 9;
         printf(" %-2d) ",
                0);
      }
      printf("Exit");
      menu_print_padding(" ",
                         ( sz - len ));
      printf(MENU_VERT);
      printf("\n");

      /* Bottom Border */
      printf(MENU_BL_CORNER);
      menu_print_padding(MENU_HORZ,
                         sz);
      printf(MENU_BR_CORNER);
      printf("\n");
   }
   else
   {
      retVal = -1;
   }
   return retVal;
}

/******************************************************************************/
/**
 * <summary>
 * Runs a menu, allowing for selecting functions.
 * If a menu item does not have a function pointer, it will not be able to be selected.
 * </summary>
 *
 * @param[in]  p_menu Pointer to the menu struct array
 *
 * @return -1  Menu is empty or does not exist
 * @return  0  Menu ran successfully and has exited
 */
/******************************************************************************/
int32_t menu_run(menu_list_t* p_menu)
{
   int32_t retVal = 0;
   int32_t choice = -1;
   void* arg1;
   void* arg2;
   void (*functionRun)(void*,
                       void*);

   if (0 == retVal)
   {
      while (-1 == choice)
      {
         retVal = menu_print(p_menu);
         /* Loop for an argument */
         while (scanf("%d",
                      &choice) == 0)
            ;

         if (choice == 0)
         {
            retVal = 1;
         }
         if (retVal == 0)
         {
            choice -= 1;

            if (( p_menu->lastEntry >= choice ) && ( NULL != p_menu->items[choice].func ))
            {
               functionRun = p_menu->items[choice].func;
               arg1 = p_menu->items[choice].arg1;
               arg2 = p_menu->items[choice].arg2;
               functionRun(arg1,
                           arg2);
            }
            else
            {
               printf("Not a valid choice\n");
               choice = -1;
            }
         }
      }
   }
   return retVal;
}

/*-----------------------------------------------------------------------------
 *                            Private Functions
 *----------------------------------------------------------------------------*/

/*
 * Return the length of the longest string in the menu, plus the graphics
 */
uint32_t menu_get_print_size(menu_list_t* p_menu)
{
   int32_t i;
   /* 4 is the length of the word "Exit" */
   uint32_t longestLine = 4;
   /* Figure out the longest line length */
   for (i = 0; i < ( p_menu->lastEntry + 1 ); i++)
   {
      if (longestLine < strlen(p_menu->items[i].name))
      {
         longestLine = strlen(p_menu->items[i].name);
      }
   }
   if (10 > p_menu->lastEntry) /* If we have less than 10 entries */
   {
      /* Add 4 to that to account for the select number */
      longestLine += 4;
   }
   else
   {
      longestLine += 5;
   }

   /* Compare against title */
   if (longestLine < strlen(p_menu->title))
   {
      longestLine = strlen(p_menu->title);
   }

   /* 4 is for graphics endings and spacing */
   return longestLine + 4;
}

/*
 * Prints a character, len number of times (cleaner than looping inline)
 */
void menu_print_padding(const char* ch,
                        uint32_t len)
{
   while (len)
   {
      printf(ch);
      len--;
   }
}

menu_item_t TestMenuItems[16];
menu_list_t TestMenu;
/*
   if (inputAvailable())
   {
      menu_init("PID Tuner",
                &TestMenu,
                TestMenuItems,
                16);
      menu_option_register("FF",
                           0,
                           0,
                           0,
                           &TestMenu);
      menu_option_register("P",
                           0,
                           0,
                           0,
                           &TestMenu);
      menu_option_register("I",
                           0,
                           0,
                           0,
                           &TestMenu);
      menu_option_register("D",
                           0,
                           0,
                           0,
                           &TestMenu);
      menu_run(&TestMenu);
   }
   */
