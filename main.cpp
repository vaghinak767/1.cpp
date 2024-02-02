#include "SpreadSheet.h"

int main() {
   SpreadSheet ob(3, 3);
   ob.setCell(0,0,44);
   ob.setCell(2,2,"hau");
   ob.addRow(2);
   ob.setCell(4,1,"exav");
   ob.addColumn(88);
   ob.setCell(1,5,5467867);
   ob.setCell(2,8,"yesdddfsfssssss");
   ob.setCell(1,5,5467867);
   ob.setCell(2,8,"sssss");
   ob.setCell(1,2,243867);
   ob.setCell(2,4,"yessss");
 
   ob.printSheet();

}
