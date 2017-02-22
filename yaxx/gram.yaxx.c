/* Allocate input grammar variables for bison,
   Copyright 1984, 1986, 1989, 2001 Free Software Foundation, Inc.

   This file is part of Bison, the GNU Compiler Compiler.

   Bison is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   Bison is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Bison; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */


#include "system.h"
#include "gram.h"
#include "reader.h"

/* comments for these variables are in gram.h  */

int nitems;
int nrules;
int nsyms;
int ntokens;
int nvars;

short *ritem = NULL;
rule_t *rule_table = NULL;
short *rprec = NULL;
short *rprecsym = NULL;
short *sprec = NULL;
short *rassoc = NULL;
short *sassoc = NULL;
short *token_translations = NULL;
char **token_types = NULL;

int start_symbol;

int max_user_token_number;

int semantic_parser;

int pure_parser;

int error_token_number;


/*------------------------.
| Dump RITEM for traces.  |
`------------------------*/

void
ritem_print (FILE *out)
{
  int i;
  fputs ("RITEM\n", out);
  for (i = 0; ritem[i]; ++i)
    if (ritem[i] > 0)
      fprintf (out, "  %s", tags[ritem[i]]);
    else
      fprintf (out, "  (rule %d)\n", -ritem[i]);
  fputs ("\n\n", out);
}


/*------------------------------------------.
| Return the size of the longest rule RHS.  |
`------------------------------------------*/

size_t
ritem_longest_rhs (void)
{
  short *itemp;
  int length;
  int max;

  length = 0;
  max = 0;
  for (itemp = ritem; *itemp; itemp++)
    if (*itemp > 0)
      {
	length++;
      }
    else
      {
	if (length > max)
	  max = length;
	length = 0;
      }

  return max;
}
