/*-----------------------------------------------------------------------------
    Program to find all solutions to the n-queens problem
    Bob Boothe    Feb 96

    The program finds all unique solutions.  Rotations and reflections
    are eliminated.  (For n = 8 there are 12 solutions.)

    Solutions are represented by an array of integers where a[i] = 
    the position of the queen in the i-th row.

    Rotations and reflections are eliminated by putting solutions
    into a canonical form.  There are 8 possible versions of a solution
    (4 rotations, with 2 reflections of each).  The one that has the
    lowest value in sorted order is the canonical one.  The search is
    set up so that it will find all solutions in their canonical position,
    as well as many that are not.  Any solution not found in the canonical
    position is discarded since we can be sure that the canonical one will
    also be found.  This eliminates the need for any matching against the
    other solutions.
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int *board;
int n, showallflag = 0;
int num_solns_found = 0;
int num_unique_solns = 0;
int num_nodes_searched = 0;

typedef struct solution {
  int *board;
  struct solution *next;
} SOLUTION;

SOLUTION *solns_head = NULL, *solns_tail = NULL;
int *rotations[8];

/*---- function prototypes ----*/
void search(int row, int col);
int conflict(int row, int col);
void init_solutions();
void solution();
void rotate(int *board1, int *board2);
void reflect(int *board1, int *board2);
int cmp_board(int *board1, int *board2);
void print_solutions();
void printrow(int *b, int row);
int *getnextboard();


/*-----------------------------------------------------------------------------
    recursive search
-----------------------------------------------------------------------------*/
main(int argc, char *argv[])
{
  int i, col;

  if (argc == 1)
    {
      fprintf(stderr, "usage: %s [size] [-showall]\n", argv[0]);
      fprintf(stderr, "       size = 8 is normal chessboard\n");
      fprintf(stderr, "       -showall flag shows all solutions\n\n");

      n = -1;  /* will trigger default message */
    }
  else  /* parse arges */
    for (i = 1; i < argc; i++)
      {
	if (strcmp(argv[i], "-showall") == 0)
	  showallflag = 1;
	else                 /* assume it is number */
	  n = atoi(argv[1]);
      }

  if ((n < 4) || (n > 20))
    {
      fprintf(stderr, "using default size n = 8\n");
      n = 8;
      showallflag = 1;  /* force to  show solutions */
    }

  board = (int *)malloc(sizeof(int) * n);
  init_solutions();

  /* on first row just need to do 1st half, others will be reflections.
     on odd sizes the center square is also not needed since a rotation
     will have already been found */

  for (col = 0; col < n/2; col++)
    search(0, col);  /* row 0 */

  print_solutions();
}


/*-----------------------------------------------------------------------------
    add a piece at row, col and recursively search the next row
-----------------------------------------------------------------------------*/
void search(int row, int col)
{
  int i;

  num_nodes_searched++;

  /* search for conflict: search above diag left, vertical, diag right */
  if (conflict(row, col))
    return;                     /* found conflict */

  board[row] = col;

  if (row == n-1)               /* last row */
    solution();                 /* found a solution */
  else
    for (i = 0; i < n; i++)
      search(row+1, i);         /* recursive search next row */
}


/*-----------------------------------------------------------------------------
    test the board for a conflict
    moving up from current position checking left diagonal, vertical, and
    right diagonal by adjusting column
      movement in column is: left diag = -1, vert = 0, right diag = 1
-----------------------------------------------------------------------------*/
int conflict(int row, int col)
{
  int left, vert, right, pos;

  left = vert = right = col;
  while (row > 0)
    {
      row -= 1;
      left--;
      /* vert same */
      right++;

      pos = board[row];
      if ((pos == left)||(pos == vert)||(pos == right))
	return(1);   /* conflict */
    }
  return(0);
}

/*-----------------------------------------------------------------------------
    initialize work space for solutions routine
    need storage for rotations 2-7   
-----------------------------------------------------------------------------*/
void init_solutions()
{
  int i;

  for (i = 2; i <= 7; i++)
    rotations[i] = (int *)malloc(sizeof(int) * n);
}


/*-----------------------------------------------------------------------------
    test a new solution to see if it is in canonical form
    construct rotations and reflections:
      0 = orig
      1 =  reflection        skip since can't be canonically lower than orig
      2 = orig rot cw
      3 =  reflection
      4 = orig rot cw twice
      5 =  reflection
      6 = orig rot cw 3
      7 = reflection
-----------------------------------------------------------------------------*/
void solution()
{
  int i;
  int *newsoln;
  SOLUTION *node;

  num_solns_found++;

  /*---- construct rotations and reflections ----*/
  rotate(board, rotations[2]);
  rotate(rotations[2], rotations[4]);
  rotate(rotations[4], rotations[6]);

  reflect(rotations[2], rotations[3]);
  reflect(rotations[4], rotations[5]);
  reflect(rotations[6], rotations[7]);

  /*---- check if orig board is lowest ----*/
  for (i = 2; i <= 7; i++)
    if (cmp_board(board, rotations[i]) > 0)
      return;                              /* not canonical */

  /*---- copy board and add it to solns list ----*/
  num_unique_solns++;
  newsoln = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
    newsoln[i] = board[i];

  node = (SOLUTION*)malloc(sizeof(SOLUTION));
  node->board = newsoln;
  node->next = NULL;

  /*---- add to list ----*/
  if (solns_head == NULL)
    solns_head = solns_tail = node;
  else
    {
      solns_tail->next = node;
      solns_tail = node;
    }
}


/*-----------------------------------------------------------------------------
    make board2 a ClockWise rotation of board1
-----------------------------------------------------------------------------*/
void rotate(int *board1, int *board2)
{
  int row, col;

  for (row = 0; row < n; row++)
    {
      col = board1[row];
      /*     row    col     */
      board2[col] = n-1-row;
    }
}

/*-----------------------------------------------------------------------------
    make board2 a reflection  <---->
-----------------------------------------------------------------------------*/
void reflect(int *board1, int *board2)
{
  int row, col;

  for (row = 0; row < n; row++)
    {
      col = board1[row];
      board2[row] = n-1-col;
    }
}



/*-----------------------------------------------------------------------------
    compare the two boards
    return negative if board1 is before b2
           zero if equal
           positive if after
-----------------------------------------------------------------------------*/
int cmp_board(int *board1, int *board2)
{
  int row, diff;

  for (row = 0; row < n; row++)
    {
      diff = board1[row] - board2[row];
      if (diff != 0)
	return(diff);
    }
  return(diff);
}


#define LINELENGTH 78
#define SPACING 2
#define MAXLAYOUTCOLS (LINELENGTH / 4)  /* upper limit on layout */

/*-----------------------------------------------------------------------------
    print out the solutions
-----------------------------------------------------------------------------*/
void print_solutions()
{
  int b, i, j, row, col, layoutcols;
  int *boards[MAXLAYOUTCOLS];

  if (showallflag)
    {
      layoutcols = (LINELENGTH+SPACING)/(n+SPACING); /* how many horizontal */
      if (layoutcols > MAXLAYOUTCOLS)
	layoutcols = MAXLAYOUTCOLS;

      for (b = 0; b < num_unique_solns; b += layoutcols) /* go thru all solns*/
	{
	  /*---- get boards into array ----*/
	  for (i = 0; i < layoutcols; i++)
	    boards[i] = getnextboard();

	  /*---- print them out ----*/
	  for (row = 0; row < n; row++)
	    {
	      for (i = 0; ;)
		{
		  printrow(boards[i], row);
		  i++;
		  if (i == layoutcols)
		    break;
		  for (j = 0; j < SPACING; j++)
		    putchar(' ');
		}
	      putchar('\n');
	    }
	  for (j = 0; j < SPACING; j++)
	    putchar('\n');
	}
    }

  printf("%d unique solutions (%d total solutions, %d nodes searched)\n\n",
	 num_unique_solns, num_solns_found, num_nodes_searched);
}

/*-----------------------------------------------------------------------------
    print specified row from board, ignore if board is NULL
-----------------------------------------------------------------------------*/
void printrow(int *b, int row)
{
  int i, col;

  if (b == NULL)
    return;

  col = b[row];
  for (i = 0; i < n; i++)
    if (i == col)
      putchar('*');
    else
      putchar('.');
}


/*-----------------------------------------------------------------------------
    get the next board, NULL if empty    
    don't bother freeing
-----------------------------------------------------------------------------*/
int *getnextboard()
{
  SOLUTION *item;

  item = solns_head;
  if (item == NULL)
    return (NULL);

  solns_head = item->next;
  return (item->board);
}
