

int array[6];

int TallGreen = 0;
int ShortGreen = 1;
int TallBrown = 2;
int ShortBrown = 3;
int TallYellow = 4;
int ShortYellow = 5;

void GrabThePlant()
{
  //use the claw
  //pick up block 
  //drop in basket.
  
}


void ShouldIGetThePlant(boolean Tall, boolean Short, int Color)
{
  if( (Tall || Short) && Color > 0) //Color = 1,2,3 (green,brown,yellow)
  {
    switch(Color)
    {
      case 1: //green
        if(Tall && array[TallGreen] == 0)//if I dont have a tall green plant and this is one
        {
          array[TallGreen] = 1; // I now have this plant
          GrabThePlant();
        }
        else if(Short && array[ShortGreen] == 0)//if I dont have a tall green plant and this is one
        {
          array[ShortGreen] = 1; // I now have this plant
          GrabThePlant();
        }
        break;
      case 2: //brown
        if(Tall && array[TallBrown] == 0)//if I dont have a tall brown plant and this is one
        {
          array[TallBrown] = 1; // I now have this plant
          GrabThePlant();
        }
        else if(Short && array[ShortBrown] == 0)//if I dont have a tall Brown plant and this is one
        {
          array[ShortBrown] = 1; // I now have this plant
          GrabThePlant();
        }
        break;
      case 3: //yellow
        if(Tall && array[TallYellow] == 0)//if I dont have a tall Yellow plant and this is one
        {
          array[TallYellow] = 1; // I now have this plant
          GrabThePlant();
        }
        else if(Short && array[ShortYellow] == 0)//if I dont have a tall yellow plant and this is one
        {
          array[ShortYellow] = 1; // I now have this plant
          GrabThePlant();
        }
        break;
       default:
         break;
    }
  }
  
  
}
