select *, if(x + y > z and x + z > y and y + z > x, 'Yes', 'No') triangle from Triangle
