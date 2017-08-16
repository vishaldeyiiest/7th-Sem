/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clipping;
import static clipping.lineclip.CohenSutherlandClipper;
import static clipping.lineclip.listx;
import static clipping.lineclip.listy;
import java.awt.*;
import java.applet.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
/**
 *
 * @author vishal
 */
public class polyclip extends Applet implements ActionListener, MouseListener
{
    final int resX = 400, resY = 300;
    static int xLeft=100, xRight=500, yBottom=100, yTop=400;
    int click = 0;
    ArrayList<Integer> xp = new ArrayList<>();
    ArrayList<Integer> yp = new ArrayList<>();
    
    Button b1 = new Button("Clip");
    Button b2 = new Button("Reset");
    int c = 0;
    public void init()
    {
        this.setSize(resX, resY);
        this.setBackground(Color.WHITE);
        /*
        px[0] = 600; py[0] = 200;
        px[1] = 200; py[1] = 300;
        px[2] = 400; py[2] = 400;
        px[3] = 250; py[3] = 500;*/
        add(b1);
        b1.addActionListener(this);
        add(b2);
        b2.addActionListener(this);
        addMouseListener(this);
    }
    
    public void paint(Graphics g)
    {
        g.drawRect(xLeft, yBottom, (xRight-xLeft), (yTop-yBottom));
        if(click == 5){
            int px[] = new int[xp.size()];
            int py[] = new int[xp.size()];
            for(int i = 0; i < xp.size(); i++)
            {
                px[i] = xp.get(i);
                py[i] = yp.get(i);
            }
        if(c == 0)
            g.drawPolygon(px, py, xp.size());
        if(c == 1)
        {
            for(int i = 0; i < xp.size(); i++)
            {
                Point P0 = new Point(px[i], py[i]);
                Point P1 = new Point(px[(i+1)%xp.size()], py[(i+1)%xp.size()]);
                CohenSutherlandClipper(g, P0, P1); 
                
            }
           /* Point P0 = new Point(px[2], py[2]);
            Point P1 = new Point(px[0], py[0]);
            CohenSutherlandClipper1(g, P0, P1);*/
            int x[] = new int[listx.size()];
            int y[] = new int[listx.size()];
            System.out.println(listx.size());
            for(int i = 0; i < listx.size(); i++)
            {
                x[i] = listx.get(i);
                y[i] = listy.get(i);
                System.out.println(x[i]+" "+y[i]);
            }
            //g.setColor(Color.red);
            g.fillPolygon(x, y, listx.size());
        }}
    }
   
    @Override
    public void actionPerformed(ActionEvent e) 
    {
        if(e.getSource() == b2)
        {
            c = 0;
            click = 0;
            repaint();
            listx.clear();
            listy.clear();
            xp.clear();
            yp.clear();
        }
        if(e.getSource() == b1)
        {
            c = 1;
            repaint();
        }
       // throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        xp.add(e.getX());
        yp.add(e.getY());
        click++;
        System.out.println(click);
        repaint();
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mousePressed(MouseEvent e) {
       // throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mouseEntered(MouseEvent e) {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mouseExited(MouseEvent e) {
  //      throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}
