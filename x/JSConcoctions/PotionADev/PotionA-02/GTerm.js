import * as GTermCharModule from "./GTermChar.js";

export class GTerm {
  constructor(gConfig,gFont) {
    this.gConfig=gConfig;
    this.gFont=gFont;
    this.x=gConfig.screenOffsetX;
    this.y=gConfig.screenOffsetY;
    this.width=gConfig.screenWidth;
    this.height=gConfig.screenHeight;
    this.pointSize=gConfig.termPointSize;
    this.palette=gConfig.palette;
 
    this.gTermChars=[];
    
    this.termBackColorPaletteIndex=gConfig.termBackColorPaletteIndex;
    this.termForeColorPaletteIndex=gConfig.termForeColorPaletteIndex;

    this.posX=gConfig.screenOffsetX;
    this.posY=gConfig.screenOffsetY;

  }
 
  draw(ctx) {
    for(var i=0;i<gTermChars.length;i++) {
      putch(ctx,gTermChars[i].text);
    }
  }
 
  putch(ctx,ch) {
    var k=ch.charCodeAt(0);
    for(var j=0;j<this.gFont.height;j++) {
      for(var i=0;i<this.gFont.width;i++) {
        var bit=this.gFont.pixels[i+j*this.gFont.width+k*this.gFont.width*this.gFont.height];
        if(bit!=0) {
          ctx.fillStyle=this.palette[this.termForeColorPaletteIndex];
        } else {
          ctx.fillStyle=this.palette[this.termBackColorPaletteIndex];
        }
        ctx.fillRect(i*this.pointSize+this.posX,j*this.pointSize+this.posY,this.pointSize,this.pointSize);
      }
    }
    var width=this.pointSize*gFont.width;
    var height=this.pointSize*gFont.height;
    if(this.posX+width*2<this.gConfig.screenWidth+this.gConfig.screenOffsetX) {
      this.posX+=width;
    } else {
      if(this.posY+height*2<this.gConfig.screenHeight+this.gConfig.screenOffsetY) {
        this.posX=this.gConfig.screenOffsetX;
        this.posY+=height;
      } 
    }
  }

  setColor(foreColorPaletteIndex,backColorPaletteIndex) {
    this.foreColorPaletteIndex=foreColorPaletteIndex;
    this.backColorPaletteIndex=backColorPaletteIndex;
  }

  print(text) {
    for(let i=0;i<text.length;i++) {
      this.gTermChars.push(
        new GTermCharModule.GTermChar(text[i],
        this.foreColorPaletteIndex,
        this.backColorPaletteIndex));
    }
  }
  
  gotoxy(x,y) {
    this.posX=x;
    this.posY=y;
  }
  
}
