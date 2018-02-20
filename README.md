## Class schedule program using C
### Program features:
* Create schedule
* Save schedule data to txt file
* Retrive data from txt file

### How it works?
Lets break the program into small functionalities.

#### 2D array:
First, lets see how to create a two dimentional character array:

This is a two dimantional array. The name of this array `days[6][10]` indecates that this array will have 6 rows and 10 columns.
Each of the row contains the weakly day's name and the characters of the names represents columns.
```c
char days[6][10] = { "saturday",
                     "sunday", 
                     "monday", 
                     "tuesday", 
                     "thursday", 
                     "wednessday"};
```
For more clearify, I have ceated a table bellow to understand how two dimantional array works.

| col 0 | col 1 | col 2 | col 3 | col 4 | col 5 | col 6 | col 7 | col 8 | col 9 | col 10 |
|:-----:|-------|-------|-------|-------|-------|-------|-------|-------|-------|--------|
| row 0 | s     | a     | t     | u     | r     | d     | a     | y     |       |        |
| row 1 | s     | u     | n     | d     | a     | y     |       |       |       |        |
| row 2 | m     | o     | n     | d     | a     | y     |       |       |       |        |
| row 3 | t     | u     | e     | s     | d     | a     | y     |       |       |        |
| row 4 | t     | h     | u     | r     | s     | d     | a     | y     |       |        |
| row 5 | w     | e     | d     | n     | e     | s     | s     | d     | a     | y      |

Now if we run this code: 
```c
printf("%s", days[4][2]);
```
the output will be `u`  <br />

so if we want to print the third day name from the array, we would write this code:
```c
printf("%s", days[2]);
```
Output: `monday`  <br />
Here the `day[2]` indicates the 3rd row of the array. That's why it will print all the columns of the 3rd row.

#### Looping through array:
To print out all the day's names from our array, we can simply run a for loop.
```c
int i;
for (i=0; i<=5; i++){
  prntf("%s ", days[i];
}
```
Output: `saturday sunday monday tuesday thursday wednessday` <br />

Lets see how for loop works throug our array. <br />
We are declaring the value of `i` is eqal to `0` (`i=0`) and we are also saying that the loop will continue until the value of `i` gets `5` (`i<=5`) and evry time the loop runs, it will add 1 to `i` (`i++`).
##### So this is what happens when the loop runs:
 when `i=0` then `days[0]` so we get the output `saturday`  <br />
 when `i=1` then `days[1]` so we get the output `sunday`   <br />
 when `i=2` then `days[2]` so we get the output `monday`  <br />
 when `i=3` then `days[3]` so we get the output `tuesday`  <br />
 when `i=4` then `days[4]` so we get the output `thursday`  <br />
 when `i=5` then `days[5]` so we get the output `wednessday`  <br />
