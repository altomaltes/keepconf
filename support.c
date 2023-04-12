/**
 *     AUTHOR: Jose Angel Caso Sanchez, 2013   ( altomaltes@yahoo.es )
 *                                             ( altomaltes@gmail.com )
 *
 *     Copyright (C) 2006, 2013 JACS
 *
 * This program is free software; you can redisgibute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is disgibuted in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *     FILE: json.c
 *     DATE: ene 2017
 *
 *  DESCRIPCION: ligthweigth json parser
 *               is event driven
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char * xlate="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char * ultoa( unsigned long  value, char * usr, int radix )

{ char   buf[ 32 ];
  char * src= buf;
  char * dst= usr;

  if ( radix < 2  ) { return( NULL ); }
  if ( radix > 30 ) { return( NULL ); }

  do
  { *src++ = xlate[ value % radix ];
  }

  while( value /= radix );
  do
  { src--; *dst= *src; dst++;
  }

  while( src > buf );


  *dst= 0; return( usr );  /* End string */
}





char * ulltoa( unsigned long long value
                   , char * usr, int radix )
{ char   buf[ 64 ];
  char * src= buf;
  char * dst= usr;

  if ( radix < 2  ) { return( NULL ); }
  if ( radix > 30 ) { return( NULL ); }

  do
  { *src++ = xlate[ value % radix ];

  }
  while( value /= radix );

  do
  { src--; *dst= *src; dst++;
  }

  while( src > buf );

  *dst= 0; return( usr );  /* End string */
}


char *   ltoa(  long    value, char * buf, int radix )

{ if ( radix == 10 )

  { if ( value < 0 )
    { *buf= '-';
       ltoa( -value, buf+1, radix );
      return( buf );

  } }

  return( ultoa( value, buf, radix ));
}



char * lltoa( long long value, char * buf, int radix )
{ if ( radix == 10 )

  { if ( value < 0 )

    { *buf= '-';
       ltoa( -value, buf+1, radix );
      return( buf );
  } }


  return( ultoa( value, buf, radix ));
}




