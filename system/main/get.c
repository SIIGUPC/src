/* Output parameters from the header.
   
Takes: par1 par2 ...
*/
/*
  Copyright (C) 2004 University of Texas at Austin
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <stdio.h>
#include <string.h>

#include <rsf.h>

int main (int argc, char* argv[])
{
    int i;
    char *string, *key;
    bool parform;
    sf_file in=NULL;

    sf_init (argc,argv);
    in = sf_input ("in");

    if(!sf_getbool("parform",&parform)) parform=true;
    /* If y, print out parameter=value. If n, print out value. */

    for (i = 1; i < argc; i++) {
	key = argv[i];
	if (NULL != strchr(key,'=')) continue;
	string = sf_histstring(in,key);
	if (NULL == string) {
	    sf_warning("No key %s",key);
	} else {
	    if (parform) printf ("%s=",key);
	    printf("%s\n",string);
	} 
    }

    if (in != NULL) sf_fileclose(in);
    exit(0);
}
