/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clipping;
import java.awt.*;
import java.applet.*;
import java.awt.event.*;
import java.util.ArrayList;
/**
 *
 * @author vishal
 */
public class lineclip extends Applet implements ActionListener
{
    final int resX = 400, resY = 300;
    static int xLeft=100, xRight=500, yBottom=100, yTop=400;
    Point P0, P1;
    Button b1 = new Button("Clip");
    Button b2 = new Button("Reset");
    Label l1 = new Label("x1 = ");
    Label l2 = new Label("y1 = ");
    Label l3 = new Label("x2 = ");
    Label l4 = new Label("y2 = ");
    TextField t1 = new TextField(3);
    TextField t2 = new TextField(3);
    TextField t3 = new TextField(3);
    TextField t4 = new TextField(3);
    int c = 0;
    int points = 0;
    public static ArrayList<Integer> listx = new ArrayList<>();
    public static ArrayList<Integer> listy = new ArrayList<>();
    @Override
    public void init()
    {
        this.setSize(resX, resY);
        this.setBackground(Color.WHITE);
        add(b1);
        b1.addActionListener(this);
        add(b2);
        b2.addActionListener(this);
        P0 = new Point(200, 500);
        P1 = new Point(100, 200);
      /*  add(l1); add(t1);
        add(l2); add(t2);
        add(l3); add(t3);
        add(l4); add(t4);*/
        //addMouseListener(this);
    }
    
    @Override
    public void paint(Graphics g)
    {
        
        g.drawRect(xLeft, yBottom, (xRight-xLeft), (yTop-yBottom));
        if(c == 0)
            g.drawLine(P0.x, P0.y, P1.x, P1.y);
        if(c == 1)
            CohenSutherlandClipper(g, P0, P1);
            //g.drawLine(P0.x, P0.y, P1.x, P1.y);
    }
    private static int Codes(Point P)
    {
        int Code = 0; 
        if(P.y > yTop) 
            Code += 1; /* code for above */
        else if(P.y < yBottom) 
            Code += 2; /* code for below */
        if(P.x > xRight) 
            Code += 4; /* code for right */
        else if(P.x < xLeft) 
            Code += 8; /* code for left */

        return Code;
    }

    private static boolean rejectCheck(int outCode1, int outCode2)
    {
        if((outCode1 & outCode2) != 0) 
            return true;
        return false; 
    } 

    private static boolean acceptCheck(int outCode1, int outCode2)
    {
        if((outCode1 == 0) && (outCode2 == 0))
            return true;
        return false; 
    }

    static void CohenSutherlandClipper(Graphics g, Point P0, Point P1)
    {
        int outCode0,outCode1; 
        Point t0 = new Point(P0), t1 = new Point(P1);
        while(true)
        {
            outCode0 = Codes(t0);
            outCode1 = Codes(t1);
            if(rejectCheck(outCode0, outCode1)) 
                break;
            if(acceptCheck(outCode0, outCode1)) 
                break;
            if(outCode0 == 0)
            {
                int tempCoord; int tempCode;
                tempCoord = t0.x; t0.x= t1.x; t1.x = tempCoord;
                tempCoord = t0.y; t0.y= t1.y; t1.y = tempCoord;
                tempCode = outCode0; outCode0 = outCode1; outCode1 = tempCode;
            } 
            if((outCode0 & 1) != 0 ) 
            { 
                
                t0.x += (t1.x - t0.x)*(yTop - t0.y)/(t1.y - t0.y);
                t0.y = yTop;
            }
            else if((outCode0 & 2) != 0 ) 
            { 
                t0.x += (t1.x - t0.x)*(yBottom - t0.y)/(t1.y - t0.y);
                t0.y = yBottom;
            }
            else if((outCode0 & 4) != 0 ) 
            {   
                t0.y += (t1.y - t0.y)*(xRight - t0.x)/(t1.x - t0.x);
                t0.x = xRight;
            }
            else if((outCode0 & 8) != 0 ) 
            { 
                t0.y += (t1.y - t0.y)*(xLeft - t0.x)/(t1.x - t0.x);
                t0.x = xLeft;
            }
        } 
        g.drawLine(t0.x, t0.y, t1.x, t1.y);
        listx.add(t0.x);
        listy.add(t0.y);
      //  listx.add(t1.x);
        //listy.add(t1.y);
    } 
    @Override
    public void actionPerformed(ActionEvent e) 
    {
        if(e.getSource() == b2)
        {
            c = 0;
            repaint();
        }
        if(e.getSource() == b1)
        {
            c = 1;
            repaint();
        }
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
  
} 
