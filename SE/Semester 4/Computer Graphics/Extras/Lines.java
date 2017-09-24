import java.awt.*;
import javax.swing.*;

public class Lines extends JFrame{
public Lines(){
super("Line Styles");
setSize(400,400);
setVisible(true);
}

Stroke[] linestyles=new Stroke[]{
new BasicStroke(1.0f, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL),
new BasicStroke(25.0f, BasicStroke.CAP_SQUARE, BasicStroke.JOIN_MITER),
new BasicStroke(1.0f, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND),};

Stroke thindashed=new BasicStroke(2.0f,BasicStroke.CAP_BUTT,BasicStroke.JOIN_BEVEL,1.0f, new float[] {8.0f,3.0f,2.0f,3.0f},0.0f);
final static float dash1[]={10.0f};
final static BasicStroke dashed =new BasicStroke(1.0f, BasicStroke.CAP_BUTT,BasicStroke.JOIN_MITER, 10.0f, dash1, 0.0f);
final static float thick1[]={10.0f};
final static BasicStroke thickdash =new BasicStroke(10.0f, BasicStroke.CAP_BUTT,BasicStroke.JOIN_MITER, 10.0f, thick1, 0.0f);

public void paint(Graphics g){
int xpoints[]={220,350,350,220};
int ypoints[]={220,220,320,320};
int npoints=4;

int xpoints1[]={60,120,180};
int ypoints1[]={320,220,320};
int npoints1=3;

Graphics2D g2d = (Graphics2D) g;
super.paint(g);
((Graphics2D)g).setStroke(dashed);
g.setColor(Color.red);
g2d.drawLine(50,50,200,50);
g2d.setColor(Color.black);
g.drawString("Dashed Line", 210,55);
((Graphics2D)g).setStroke(thindashed);
g.setColor(Color.blue);
g2d.drawLine(50,90,200,90);
g2d.setColor(Color.black);
g.drawString("Thin Dashed Line", 210,95);

((Graphics2D)g).setStroke(thickdash);
g.setColor(Color.green);
g2d.drawLine(50,130,200,130);
g2d.setColor(Color.black);
g.drawString("Thick Dashed Line", 210,135);

((Graphics2D)g).setStroke(linestyles[0]);
g.setColor(Color.red);
g2d.drawLine(50,170,200,170);
g2d.setColor(Color.black);
g.drawString("Line", 210,175);

}

public static void main(String[] args){
Lines application = new Lines();
application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}
}

