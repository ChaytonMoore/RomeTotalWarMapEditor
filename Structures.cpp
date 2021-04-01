#include "Structures.h"
//This file contains all the functions regarding the the structures.
struct SubTileRow
{
  std::vector<int> Data;
};

std::vector<RowData> DeriveRoughness(std::vector<RowData> input)
{
  //This function generates the roughness from the heightmap.
  //I'm going into this having no idea what's going to be the algorithm
  
   //Firstly might as well copy the heightmap value into the roughness value.
   //Create a list of variable size of the roughness.
   std::vector<SubTileRow> Roughness;
   for( int i = 0; i < input.size(); i++ ) 
   {
        Roughness.push_back(new SubTileRow);
        for ( int j = 0; j < input[i].Data.size(); j++ ) 
        {
          Roughness.back().Data.push_back(input[i].Data[j].height[0]);
          Roughness.back().Data.push_back(input[i].Data[j].height[1]);
        }
     
        Roughness.push_back(new SubTileRow);
        for ( int j = 0; j < input[i].Data.size(); j++ ) 
        {
          Roughness.back().Data.push_back(input[i].Data[j].height[2]);
          Roughness.back().Data.push_back(input[i].Data[j].height[3]);
        }
   }
   //Now that all the data has been copied over time to perform some edits. Firstly a single high point surrounded by a load of low points should be smoothed out
   //if surrounding points all 50% lower then the point will be changed to be 40% lower
  bool Reducetemp;
  for(int i = 0; i < Roughness.size(); i++)
  {
    //Reset to null eachtime
    Reduce = false;
    for(int j = 0; j < Roughness[i].Data.size(); j++)
    {
      //Will need validation
      if(Roughness[i+1].Data[j] > 0.5 * Roughness[i].Data[j])
      {
       Reduce = true; 
        
      }
      
    }
    
    
  }

}
