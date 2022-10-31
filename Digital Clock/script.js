var d=new Date();
var mytime;
var day;
var month;

document.getElementById(d.getDay()).style.color="blue";

if(d.getDate()<10){
    day='0'+d.getDate();
}
else{
    day=d.getDate();
}

switch(d.getMonth()){
    case 0:
        month="Jan";
        break;
    case 1:
        month="Feb";
        break;
    case 2:
        month="Mar";
        break;
    case 3:
        month="Apr";
        break;
    case 4:
        month="May";
        break;
    case 5:
        month="Jun";
        break;
    case 6:
        month="Jul";
        break;
    case 7:
        month="Aug";
        break;
    case 8:
        month="Sep";
        break;
    case 9:
        month="Oct";
        break;
    case 10:
        month="Nov";
        break;
    case 11:
        month="Dec";
        break;


}

document.getElementById("date").innerHTML=day+" "+month+" "+d.getFullYear();


time();

function time(){
       
    var p=new Date();
    if(p.getHours()<10){
        document.getElementById("hr").innerHTML='0'+p.getHours();
    }
    else{
        document.getElementById("hr").innerHTML=p.getHours();
    }

    if(p.getMinutes()<10){
        document.getElementById("min").innerHTML='0'+p.getMinutes();
    }
    else{
        document.getElementById("min").innerHTML=p.getMinutes();
    }

    if(p.getSeconds()<10){
        document.getElementById("sec").innerHTML='0'+p.getSeconds();
    }
    else{
        document.getElementById("sec").innerHTML=p.getSeconds();
    }

    if(p.getHours()>12 && p.getHours()<=24){
        document.getElementById("x").innerHTML="P.M";
        document.getElementById("x").style.fontSize="20px";
    }
    else{
        document.getElementById("x").innerHTML="A.M";
        document.getElementById("x").style.fontSize="20px";
    }

    setTimeout(time,1000);
}