/*
view x and y in base 3
every position in x and y must
- both equal 1
- both not equal 1
1 1 0 1 2
1 1 2 1 0
+1 
1 1 0 2 0
1 1 2 1 1
doesn't work
need to +3 because 0 and 2 combination
1 1 0 2 2
1 1 2 2 0
can keep adding +3 so d/3 or smth like that

1 1 0 1 0
1 1 2 1 0
+0 to + 8
+27 to +35
... 
if position i is (0, 2) then add 3^i once every 3 times 
combination (0, 1) is the same since +2 makes (2, 0) 

2 1 0 1 0
2 1 1 1 0
add 2*3^(2)

2 1 2 1 0
2 2 0 1 0
*/
