///////////////////////////////////////////////////////////////LIBRARIES/////////////////////////////////////////////////////////////////
import processing.serial.*;
import java.io.*;
PFont f;
//////////////////////////////////////////////////////////////DECLARATION//////////////////////////////////////////////////////////////////
String subtext;
Serial myPort;
PFont font;
Button button;
Button button1,button2,button3,button4,button5,button6,button7,button8,button9,button10,button11,button12,button13,button14,button15,button16,button17,button18,button19,button20,button21,button22,button23,button24,button25,button26,button27,button28,button29,button30,button31,button32,button33,button34,button35,button36,button37,button38,button39,button40,button41,button42,button43,button44,button45,button46,button47,button48,button49,button50,button51,button52,button53,button54,button55,button56,button57,button58,button59,button60,button61,button62,button63,button64;
int val1,val2,val3,val4,val5,val6,val7,val8,val9,val10,val11,val12,val13,val14,val15,val16,val17,val18,val19,val20,val21,val22,val23,val24,val25,val26,val27,val28,val29,val30,val31,val32,val33,val34,val35,val36,val37,val38,val39,val40,val41,val42,val43,val44,val45,val46,val47,val48,val49,val50,val51,val52,val53,val54,val55,val56,val57,val58,val59,val60,val61,val62,val63,val64;
////////////////////////////////////////////////////////////////////SETUP FUNCTION///////////////////////////////////////////////////////
void setup(){
  size(270,305);
  f = createFont("Arial",12,true); 
  button = new Button(110,230,40,25,"PRINT",10,255);
  init();
  myPort = new Serial(this, "COM5", 9600);
  myPort.bufferUntil('\n');
}
/////////////////////////////////////////////////////////////////////DRAW FUNCTION/////////////////////////////////////////////////////////
void draw(){
  background(100,149,237);
  textFont(f,12); 
  fill(255);         
  text("CUSTOM CHARACTER GENERATOR",25,40);
  button.Draw();
  initdraw();
}

////////////////////////////////////////////////////////////////CLASS DEFINITION////////////////////////////////////////////////////////
class Button
{
  private int x, y, width, height;
  private PFont font;
  private String label;
  private int fontSize;
  private int fillcolor;
  private int delay = 0, framesPassed = 0;
  
  public Button(int x, int y, int width, int height, String label, int fontSize,int filcolor)
  {
    this.x = x;
    this.y = y;
    this.width = width;
    this.height = height;
    this.font = createFont("Arial", 16, true);
    this.fontSize = fontSize;
    this.label = label;
    this.fillcolor=filcolor;
  }
  
  public void Draw()
  {
    fill(fillcolor);
    stroke(0);
    rect(x, y, width, height);
    textFont(font, fontSize);
    fill(0);
    noStroke();
    
    text(label, x + 5, y + (height - fontSize) / 2 + (height / 2));
    
    if(framesPassed < delay)
    {
      framesPassed++;
    }
  }
  
  
  public void colorswap()
  {
    if (this.getbuttoncolor()==255)
    {
      stroke(255);
      fill(0);
      noStroke();
    }
    else
    {
      stroke(0);
      fill(255);
      noStroke();
    }
  }
  
  
  public int getbuttoncolor()
  {
    return this.fillcolor;
  }
  public void SetFrameDelay(int delay)
  {
    this.delay = delay;
  }
  
  public boolean IsPressed()
  {    
    if(!mousePressed)
    {
      return false;
    }
    
    if(mouseX >= x && mouseX <= x + width)
    {
      if(mouseY >= y && mouseY <= y + (height))
      {
        if(framesPassed == delay)
        {
          framesPassed = 0;
          return true;
        }
      }
    }
    
    return false;
  }
}

//////////////////////////////////////////////////////////////////INITIALIZATION AND BUTTON PROCEDURES//////////////////////////////////////////////////////

void init()
{
button1=new Button(50,50,20,20,"   ",5,255);
button2=new Button(70,50,20,20,"   ",5,255);
button3=new Button(90,50,20,20,"   ",5,255);
button4=new Button(110,50,20,20,"   ",5,255);
button5=new Button(130,50,20,20,"   ",5,255);
button6=new Button(150,50,20,20,"   ",5,255);
button7=new Button(170,50,20,20,"   ",5,255);
button8=new Button(190,50,20,20,"   ",5,255);

button9=new Button(50,70,20,20,"   ",5,255);
button10=new Button(70,70,20,20,"   ",5,255);
button11=new Button(90,70,20,20,"   ",5,255);
button12=new Button(110,70,20,20,"   ",5,255);
button13=new Button(130,70,20,20,"   ",5,255);
button14=new Button(150,70,20,20,"   ",5,255);
button15=new Button(170,70,20,20,"   ",5,255);
button16=new Button(190,70,20,20,"   ",5,255);

button17=new Button(50,90,20,20,"   ",5,255);
button18=new Button(70,90,20,20,"   ",5,255);
button19=new Button(90,90,20,20,"   ",5,255);
button20=new Button(110,90,20,20,"   ",5,255);
button21=new Button(130,90,20,20,"   ",5,255);
button22=new Button(150,90,20,20,"   ",5,255);
button23=new Button(170,90,20,20,"   ",5,255);
button24=new Button(190,90,20,20,"   ",5,255);

button25=new Button(50,110,20,20,"   ",5,255);
button26=new Button(70,110,20,20,"   ",5,255);
button27=new Button(90,110,20,20,"   ",5,255);
button28=new Button(110,110,20,20,"   ",5,255);
button29=new Button(130,110,20,20,"   ",5,255);
button30=new Button(150,110,20,20,"   ",5,255);
button31=new Button(170,110,20,20,"   ",5,255);
button32=new Button(190,110,20,20,"   ",5,255);

button33=new Button(50,130,20,20,"   ",5,255);
button34=new Button(70,130,20,20,"   ",5,255);
button35=new Button(90,130,20,20,"   ",5,255);
button36=new Button(110,130,20,20,"   ",5,255);
button37=new Button(130,130,20,20,"   ",5,255);
button38=new Button(150,130,20,20,"   ",5,255);
button39=new Button(170,130,20,20,"   ",5,255);
button40=new Button(190,130,20,20,"   ",5,255);

button41=new Button(50,150,20,20,"   ",5,255);
button42=new Button(70,150,20,20,"   ",5,255);
button43=new Button(90,150,20,20,"   ",5,255);
button44=new Button(110,150,20,20,"   ",5,255);
button45=new Button(130,150,20,20,"   ",5,255);
button46=new Button(150,150,20,20,"   ",5,255);
button47=new Button(170,150,20,20,"   ",5,255);
button48=new Button(190,150,20,20,"   ",5,255);

button49=new Button(50,170,20,20,"   ",5,255);
button50=new Button(70,170,20,20,"   ",5,255);
button51=new Button(90,170,20,20,"   ",5,255);
button52=new Button(110,170,20,20,"   ",5,255);
button53=new Button(130,170,20,20,"   ",5,255);
button54=new Button(150,170,20,20,"   ",5,255);
button55=new Button(170,170,20,20,"   ",5,255);
button56=new Button(190,170,20,20,"   ",5,255);

button57=new Button(50,190,20,20,"   ",5,255);
button58=new Button(70,190,20,20,"   ",5,255);
button59=new Button(90,190,20,20,"   ",5,255);
button60=new Button(110,190,20,20,"   ",5,255);
button61=new Button(130,190,20,20,"   ",5,255);
button62=new Button(150,190,20,20,"   ",5,255);
button63=new Button(170,190,20,20,"   ",5,255);
button64=new Button(190,190,20,20,"   ",5,255);
}

void initdraw()
{
  button1.Draw();
button2.Draw();
button3.Draw();
button4.Draw();
button5.Draw();
button6.Draw();
button7.Draw();
button8.Draw();
button9.Draw();
button10.Draw();
button11.Draw();
button12.Draw();
button13.Draw();
button14.Draw();
button15.Draw();
button16.Draw();
button17.Draw();
button18.Draw();
button19.Draw();
button20.Draw();
button21.Draw();
button22.Draw();
button23.Draw();
button24.Draw();
button25.Draw();
button26.Draw();
button27.Draw();
button28.Draw();
button29.Draw();
button30.Draw();
button31.Draw();
button32.Draw();
button33.Draw();
button34.Draw();
button35.Draw();
button36.Draw();
button37.Draw();
button38.Draw();
button39.Draw();
button40.Draw();
button41.Draw();
button42.Draw();
button43.Draw();
button44.Draw();
button45.Draw();
button46.Draw();
button47.Draw();
button48.Draw();
button49.Draw();
button50.Draw();
button51.Draw();
button52.Draw();
button53.Draw();
button54.Draw();
button55.Draw();
button56.Draw();
button57.Draw();
button58.Draw();
button59.Draw();
button60.Draw();
button61.Draw();
button62.Draw();
button63.Draw();
button64.Draw();
}

void mousePressed()
{
  if (button.IsPressed())
  {
    subtext=make();
    //print(subtext);
    myPort.write(subtext);
  }
  
 if(button1.IsPressed()){if(button1.getbuttoncolor()==255){button1.fillcolor=0;val1=1;}else{button1.fillcolor=255;val1=0;}}
if(button2.IsPressed()){if(button2.getbuttoncolor()==255){button2.fillcolor=0;val2=1;}else{button2.fillcolor=255;val2=0;}}
if(button3.IsPressed()){if(button3.getbuttoncolor()==255){button3.fillcolor=0;val3=1;}else{button3.fillcolor=255;val3=0;}}
if(button4.IsPressed()){if(button4.getbuttoncolor()==255){button4.fillcolor=0;val4=1;}else{button4.fillcolor=255;val4=0;}}
if(button5.IsPressed()){if(button5.getbuttoncolor()==255){button5.fillcolor=0;val5=1;}else{button5.fillcolor=255;val5=0;}}
if(button6.IsPressed()){if(button6.getbuttoncolor()==255){button6.fillcolor=0;val6=1;}else{button6.fillcolor=255;val6=0;}}
if(button7.IsPressed()){if(button7.getbuttoncolor()==255){button7.fillcolor=0;val7=1;}else{button7.fillcolor=255;val7=0;}}
if(button8.IsPressed()){if(button8.getbuttoncolor()==255){button8.fillcolor=0;val8=1;}else{button8.fillcolor=255;val8=0;}}
if(button9.IsPressed()){if(button9.getbuttoncolor()==255){button9.fillcolor=0;val9=1;}else{button9.fillcolor=255;val9=0;}}
if(button10.IsPressed()){if(button10.getbuttoncolor()==255){button10.fillcolor=0;val10=1;}else{button10.fillcolor=255;val10=0;}}
if(button11.IsPressed()){if(button11.getbuttoncolor()==255){button11.fillcolor=0;val11=1;}else{button11.fillcolor=255;val11=0;}}
if(button12.IsPressed()){if(button12.getbuttoncolor()==255){button12.fillcolor=0;val12=1;}else{button12.fillcolor=255;val12=0;}}
if(button13.IsPressed()){if(button13.getbuttoncolor()==255){button13.fillcolor=0;val13=1;}else{button13.fillcolor=255;val13=0;}}
if(button14.IsPressed()){if(button14.getbuttoncolor()==255){button14.fillcolor=0;val14=1;}else{button14.fillcolor=255;val14=0;}}
if(button15.IsPressed()){if(button15.getbuttoncolor()==255){button15.fillcolor=0;val15=1;}else{button15.fillcolor=255;val15=0;}}
if(button16.IsPressed()){if(button16.getbuttoncolor()==255){button16.fillcolor=0;val16=1;}else{button16.fillcolor=255;val16=0;}}
if(button17.IsPressed()){if(button17.getbuttoncolor()==255){button17.fillcolor=0;val17=1;}else{button17.fillcolor=255;val17=0;}}
if(button18.IsPressed()){if(button18.getbuttoncolor()==255){button18.fillcolor=0;val18=1;}else{button18.fillcolor=255;val18=0;}}
if(button19.IsPressed()){if(button19.getbuttoncolor()==255){button19.fillcolor=0;val19=1;}else{button19.fillcolor=255;val19=0;}}
if(button20.IsPressed()){if(button20.getbuttoncolor()==255){button20.fillcolor=0;val20=1;}else{button20.fillcolor=255;val20=0;}}
if(button21.IsPressed()){if(button21.getbuttoncolor()==255){button21.fillcolor=0;val21=1;}else{button21.fillcolor=255;val21=0;}}
if(button22.IsPressed()){if(button22.getbuttoncolor()==255){button22.fillcolor=0;val22=1;}else{button22.fillcolor=255;val22=0;}}
if(button23.IsPressed()){if(button23.getbuttoncolor()==255){button23.fillcolor=0;val23=1;}else{button23.fillcolor=255;val23=0;}}
if(button24.IsPressed()){if(button24.getbuttoncolor()==255){button24.fillcolor=0;val24=1;}else{button24.fillcolor=255;val24=0;}}
if(button25.IsPressed()){if(button25.getbuttoncolor()==255){button25.fillcolor=0;val25=1;}else{button25.fillcolor=255;val25=0;}}
if(button26.IsPressed()){if(button26.getbuttoncolor()==255){button26.fillcolor=0;val26=1;}else{button26.fillcolor=255;val26=0;}}
if(button27.IsPressed()){if(button27.getbuttoncolor()==255){button27.fillcolor=0;val27=1;}else{button27.fillcolor=255;val27=0;}}
if(button28.IsPressed()){if(button28.getbuttoncolor()==255){button28.fillcolor=0;val28=1;}else{button28.fillcolor=255;val28=0;}}
if(button29.IsPressed()){if(button29.getbuttoncolor()==255){button29.fillcolor=0;val29=1;}else{button29.fillcolor=255;val29=0;}}
if(button30.IsPressed()){if(button30.getbuttoncolor()==255){button30.fillcolor=0;val30=1;}else{button30.fillcolor=255;val30=0;}}
if(button31.IsPressed()){if(button31.getbuttoncolor()==255){button31.fillcolor=0;val31=1;}else{button31.fillcolor=255;val31=0;}}
if(button32.IsPressed()){if(button32.getbuttoncolor()==255){button32.fillcolor=0;val32=1;}else{button32.fillcolor=255;val32=0;}}
if(button33.IsPressed()){if(button33.getbuttoncolor()==255){button33.fillcolor=0;val33=1;}else{button33.fillcolor=255;val33=0;}}
if(button34.IsPressed()){if(button34.getbuttoncolor()==255){button34.fillcolor=0;val34=1;}else{button34.fillcolor=255;val34=0;}}
if(button35.IsPressed()){if(button35.getbuttoncolor()==255){button35.fillcolor=0;val35=1;}else{button35.fillcolor=255;val35=0;}}
if(button36.IsPressed()){if(button36.getbuttoncolor()==255){button36.fillcolor=0;val36=1;}else{button36.fillcolor=255;val36=0;}}
if(button37.IsPressed()){if(button37.getbuttoncolor()==255){button37.fillcolor=0;val37=1;}else{button37.fillcolor=255;val37=0;}}
if(button38.IsPressed()){if(button38.getbuttoncolor()==255){button38.fillcolor=0;val38=1;}else{button38.fillcolor=255;val38=0;}}
if(button39.IsPressed()){if(button39.getbuttoncolor()==255){button39.fillcolor=0;val39=1;}else{button39.fillcolor=255;val39=0;}}
if(button40.IsPressed()){if(button40.getbuttoncolor()==255){button40.fillcolor=0;val40=1;}else{button40.fillcolor=255;val40=0;}}
if(button41.IsPressed()){if(button41.getbuttoncolor()==255){button41.fillcolor=0;val41=1;}else{button41.fillcolor=255;val41=0;}}
if(button42.IsPressed()){if(button42.getbuttoncolor()==255){button42.fillcolor=0;val42=1;}else{button42.fillcolor=255;val42=0;}}
if(button43.IsPressed()){if(button43.getbuttoncolor()==255){button43.fillcolor=0;val43=1;}else{button43.fillcolor=255;val43=0;}}
if(button44.IsPressed()){if(button44.getbuttoncolor()==255){button44.fillcolor=0;val44=1;}else{button44.fillcolor=255;val44=0;}}
if(button45.IsPressed()){if(button45.getbuttoncolor()==255){button45.fillcolor=0;val45=1;}else{button45.fillcolor=255;val45=0;}}
if(button46.IsPressed()){if(button46.getbuttoncolor()==255){button46.fillcolor=0;val46=1;}else{button46.fillcolor=255;val46=0;}}
if(button47.IsPressed()){if(button47.getbuttoncolor()==255){button47.fillcolor=0;val47=1;}else{button47.fillcolor=255;val47=0;}}
if(button48.IsPressed()){if(button48.getbuttoncolor()==255){button48.fillcolor=0;val48=1;}else{button48.fillcolor=255;val48=0;}}
if(button49.IsPressed()){if(button49.getbuttoncolor()==255){button49.fillcolor=0;val49=1;}else{button49.fillcolor=255;val49=0;}}
if(button50.IsPressed()){if(button50.getbuttoncolor()==255){button50.fillcolor=0;val50=1;}else{button50.fillcolor=255;val50=0;}}
if(button51.IsPressed()){if(button51.getbuttoncolor()==255){button51.fillcolor=0;val51=1;}else{button51.fillcolor=255;val51=0;}}
if(button52.IsPressed()){if(button52.getbuttoncolor()==255){button52.fillcolor=0;val52=1;}else{button52.fillcolor=255;val52=0;}}
if(button53.IsPressed()){if(button53.getbuttoncolor()==255){button53.fillcolor=0;val53=1;}else{button53.fillcolor=255;val53=0;}}
if(button54.IsPressed()){if(button54.getbuttoncolor()==255){button54.fillcolor=0;val54=1;}else{button54.fillcolor=255;val54=0;}}
if(button55.IsPressed()){if(button55.getbuttoncolor()==255){button55.fillcolor=0;val55=1;}else{button55.fillcolor=255;val55=0;}}
if(button56.IsPressed()){if(button56.getbuttoncolor()==255){button56.fillcolor=0;val56=1;}else{button56.fillcolor=255;val56=0;}}
if(button57.IsPressed()){if(button57.getbuttoncolor()==255){button57.fillcolor=0;val57=1;}else{button57.fillcolor=255;val57=0;}}
if(button58.IsPressed()){if(button58.getbuttoncolor()==255){button58.fillcolor=0;val58=1;}else{button58.fillcolor=255;val58=0;}}
if(button59.IsPressed()){if(button59.getbuttoncolor()==255){button59.fillcolor=0;val59=1;}else{button59.fillcolor=255;val59=0;}}
if(button60.IsPressed()){if(button60.getbuttoncolor()==255){button60.fillcolor=0;val60=1;}else{button60.fillcolor=255;val60=0;}}
if(button61.IsPressed()){if(button61.getbuttoncolor()==255){button61.fillcolor=0;val61=1;}else{button61.fillcolor=255;val61=0;}}
if(button62.IsPressed()){if(button62.getbuttoncolor()==255){button62.fillcolor=0;val62=1;}else{button62.fillcolor=255;val62=0;}}
if(button63.IsPressed()){if(button63.getbuttoncolor()==255){button63.fillcolor=0;val63=1;}else{button63.fillcolor=255;val63=0;}}
if(button64.IsPressed()){if(button64.getbuttoncolor()==255){button64.fillcolor=0;val64=1;}else{button64.fillcolor=255;val64=0;}}
}

String make()
{
 String s="";
 s=s+"B"+str(val1)+str(val2)+str(val3)+str(val4)+str(val5)+str(val6)+str(val7)+str(val8)+",";
 s=s+"B"+str(val9)+str(val10)+str(val11)+str(val12)+str(val13)+str(val14)+str(val15)+str(val16)+",";
 s=s+"B"+str(val17)+str(val18)+str(val19)+str(val20)+str(val21)+str(val22)+str(val23)+str(val24)+",";
 s=s+"B"+str(val25)+str(val26)+str(val27)+str(val28)+str(val29)+str(val30)+str(val31)+str(val32)+",";
 s=s+"B"+str(val33)+str(val34)+str(val35)+str(val36)+str(val37)+str(val38)+str(val39)+str(val40)+",";
 s=s+"B"+str(val41)+str(val42)+str(val43)+str(val44)+str(val45)+str(val46)+str(val47)+str(val48)+",";
 s=s+"B"+str(val49)+str(val50)+str(val51)+str(val52)+str(val53)+str(val54)+str(val55)+str(val56)+",";
 s=s+"B"+str(val57)+str(val58)+str(val59)+str(val60)+str(val61)+str(val62)+str(val63)+str(val64)+",";
 return s;
}