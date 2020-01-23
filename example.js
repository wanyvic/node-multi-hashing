var multiHashing = require('./build/Release/multihashing');

var algorithms = ['x11','jumphash'];
var data = new Buffer("060000004219308d165894c3d363588a0c5ee1381bba280075b873457031050000000000287cdb08ae4c0be821cd643a238d9b706a6129952403d30a11941858a3050022529def5cda5c0e1bbf946036", "hex");
console.log(data);
var hashedData = algorithms.map(function(algo){
    if (algo === 'scryptjane'){
        //scryptjane needs block.nTime and nChainStartTime (found in coin source)
        var yaCoinChainStartTime = 1367991200;
        var nTime = Math.round(Date.now() / 1000);
        return multiHashing[algo](data, nTime, yaCoinChainStartTime);
    }
    else{
        return multiHashing[algo](data);
    }
});


console.log(hashedData);
// console.log("asas")
// console.log(multiHashing.jumphash(data))
//<SlowBuffer 0b de 16 ef 2d 92 e4 35 65 c6 6c d8 92 d9 66 b4 3d 65 ..... >
