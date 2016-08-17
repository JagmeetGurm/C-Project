 gridWalk = [];

var isGoodPoint = function (x, y) {
    var c = 0;
  x = Math.abs(x);
   str = x.toString();
  len = str.length;
    for (i = 0; i < len; i++){
      x = Math.abs(x);
      str = x.toString();
      len = str.length;
      c += +str[i];
    }
   y = Math.abs(y);
  str = y.toString();
  len = str.length;
    for (i = 0;  i < len;i++ ){
      y = Math.abs(y);
      str = y.toString();
       len = str.length;
      c += +str[i];
    }
    return (c <= 19);
};

var isVisited = function (x, y) {
    
    return (gridWalk[[x, y]]);
        

    
};
var neighbour = function (x, y) {
    if (isGoodPoint(x, y) && !isVisited(x, y)) {
        gridWalk[[x, y]] = true;
        return 1 + neighbour(x - 1, y) + neighbour(x + 1, y) + neighbour(x, y - 1) + neighbour(x, y + 1);
    }

        return 0;
    
};

console.log(neighbour(0, 0));