var http = require('http');

http.createServer(function(req, res) {
    console.log('got a connection');
    var body = '';
    req.on('data', function (data) {
        body += data;
    });
    req.on('end', function () {
        console.log(JSON.parse(body).name);
        res.end();
    });
}).listen(8000, function() {
    console.log('listening on port 8000');
});