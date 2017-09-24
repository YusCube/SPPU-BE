
import java.awt.*;

import javax.swing.*;

public class polygon extends JFrame
{public polygon()
{
super("Draw square,rectangle ,polygon");
setSize(400,400);
setVisible(true);
}

public void paint(Graphics g)
{
 int xpoints[]={55,145,55,145,55};
 int ypoints[]={55,55,145,145,55};int npoints=5;

Graphics2D g2d=(Graphics2D) g;
super.paint(g);
g.setColor(Color.red);
g.drawRect(55,150,90,150);
 g.drawRect(150,150,200,200);
g2d.setColor(Color.blue);
g.drawLine(150,150,150,150);
g.drawPolygon(xpoints,ypoints,npoints);
}

public static void main(String[] args)
{ polygon application =new polygon();
  application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}
}