const char MAIN_page[] PROGMEM = R"=====(
  <!DOCTYPE html> 
  <html>
   <head> 
       <title>Nhat Nguyet</title> 
    <style> 
         body{
            background-color: black;
          }
     #khach1{
    color: rgb(252, 248, 5);
    background-color: rgb(255, 0, 21);
width: 70px; 
height: 50px;
border-radius: 10px;
border: 3px solid #f00606;
position: absolute;
left:150px;
top: 630px;
z-index:2;
cursor: pointer; /*đổi trang thái chuột khi rê vào nút nhấn*/
 }
 /* test thử hiệu ứng */
 #khach1:hover {background-color: #ec300f}
  #khach1:active {
    background-color: #b44030;
    box-shadow: 0 1px rgb(224, 19, 173);
    transform: translateY(4px);
  }
  
 
           #tlap{
                
                color: rgb(229, 255, 0);
                position: absolute;
                z-index:3;
                left:90px;
                top: 520px;  
                font-size: 30px;
            }
            #ssid{
                
                color: rgb(255, 17, 0);
                position: absolute;
                z-index:3;
                left:60px;
                top: 570px;  
                font-size: 20px;
            }
            .track {
                stroke-width: 18;
                stroke: rgb(247, 250, 247);
                fill: none;
                
            }
            
            .progress {
                stroke-width: 20;
                stroke: rgb(247, 4, 4);
                stroke-linecap: round;
                fill: none;
                transform: rotate(130deg);
                transform-origin: center;
                
            }
            #k1{
                
                color: rgb(255, 17, 0);
                position: absolute;
                z-index:3;
                left:240px;
                top: 390px;  
                font-size: 50px;
                font-family: Arial, Helvetica, sans-serif;
            }
            
            
            }
            #anh1
            {
              left:40px;
              top:30px;
              width:450px;
              position: absolute;
                z-index:1;  
            }
            #anh2
            {
              left:30px;
              top:420px;
              width:240px;
              position: absolute;
                z-index:1;  
            }
            #anh3
            {
              left:370px;
              top:400px;
              width:140px;
              position: absolute;
                z-index:1;  
            }
       </style>
       <meta charset="UTF-8">
       <script>
       setInterval(function() {
          biendoi();
          nhietdo();
        }, 500);

    function bat(){
        var ssid = document.getElementById("ssid").value;
       var xhttp = new XMLHttpRequest();
       xhttp.onreadystatechange = function(){
        if (this.readyState == 4 && this.status == 200){
        document.getElementById("thb1").innerHTML= this.responseText;
          }
        };
         xhttp.open("GET","writeEEPROM?ssid="+ssid,true);
              xhttp.send();
         }

    //=================================================================================
       
    //======================================================================================
         function tat(){
       var xhttp = new XMLHttpRequest();
       xhttp.onreadystatechange = function(){
        if (this.readyState == 4 && this.status == 200){
        document.getElementById("thb1").innerHTML= this.responseText;
          }
        };
         xhttp.open("GET","read",true);
              xhttp.send();
         }

   //==========================================================================
      function biendoi(){ 
    let progressCircle = document.querySelector(".progress");
    let radius = progressCircle.r.baseVal.value;
    var bien = document.getElementById('n1');
    var bien1=bien.innerHTML;
    let circumference = radius * 2 * Math.PI;
    progressCircle.style.strokeDasharray = circumference;
    setProgress(bien1);

    function setProgress(percent) {
        progressCircle.style.strokeDashoffset = circumference - (percent / 100) * circumference;
    }
    }          
//================================================================================================              
    function nhietdo(){
       var xhttp = new XMLHttpRequest();
       xhttp.onreadystatechange = function(){
        if (this.readyState == 4 && this.status == 200){
        document.getElementById("n1").innerHTML= this.responseText;
          }
        };
         xhttp.open("GET","laynhietdo",true);
              xhttp.send();
         }
//==========================================================================
       
    
              
              
        </script>
   </head>
   <body> 
       <h3> </h3> 
        <h3></h3>
        <svg width="450" height="450">
          <circle r="80"  cx="200" cy="290" class="track"></circle>
          <circle r="80" cx="290" cy="202" class="progress"></circle>
      </svg>
          <img id="anh1"
            src="https://user-images.githubusercontent.com/115692161/195542435-8a259a4f-24af-4930-b86a-e63d92a185c8.png" />
            <img id="anh2"
            src="https://user-images.githubusercontent.com/115692161/195548324-09f46c60-68ef-465e-8e1c-9a9ed17a14b6.jpg" />
            <img id="anh3"
            src="https://user-images.githubusercontent.com/115692161/195549802-ad71d7fa-67b3-4b5c-8e7d-dc2279ef0f42.jpg" />
     
            <p id="k1"> <span id= "n1"> 70 </span></p>
        <div id="tlap">Thiết lập nhiệt độ: </div>
        <div><input id="ssid"/></div>

      <button id="khach1" name="button" type="button"onclick="bat()">send</button>
       
       
       
   </body> 
  </html>
)=====";