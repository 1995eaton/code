var triangles = require('fs')
  .readFileSync('triangle.txt', 'utf8')
  .split('\n')
  .slice(0, -1)
  .map(function(row) {
    return row.split(/\D+/).map(function(column) {
      return +column;
    });
  });

var reduction = triangles.pop();
for (var i = triangles.length - 1; i !== -1; i--) {
  reduction = triangles[i].map(function(item, index) {
    return item + Math.max(reduction[index], reduction[index + 1]);
  });
}

console.log(reduction[0]);
