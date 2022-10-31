const express=require("express");
const bodyParser=require("body-parser");

const app=express();
app.use(bodyParser.urlencoded({extended: true}));

app.get("/bmicalculator", function(request, respond){
    respond.sendFile(__dirname+"/bmiCalculator.html")
});

app.post("/bmicalculator", function(request, respond){
    var weight=parseFloat(request.body.weight);
    var height=parseFloat(request.body.height);
    respond.send("Body Mass Index: "+(weight/(height*height)));
});

app.listen(3000, function(){
    console.log("Server started at port 3000")
});
