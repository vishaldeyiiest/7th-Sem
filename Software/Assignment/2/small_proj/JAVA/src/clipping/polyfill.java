/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clipping;
import java.awt.*;
import java.applet.*;
/**
 *
 * @author vishal
 */
public class polyfill extends Applet
{
    final int resX = 400, resY = 300;
    @Override
    public void init()
    {
        this.setSize(resX, resY);
        this.setBackground(Color.WHITE);
    }
    @Override
    public void paint(Graphics g)
    {
        Color a = Color.RED;
        Color b = Color.WHITE;
        boundaryFill4(g, 50, 100, a, b);
    }
    public void boundaryFill4(Graphics g, int x, int y, Color fill, Color boundary)
    {
        Color current;
        current = g.getColor();
        if((current.equals(boundary)) && (current.equals(fill)))
        {
            g.setColor(fill) ;
            g.drawLine(x, y, x, y);
            boundaryFill4 (g, x+1, y, fill, boundary);
            boundaryFill4 (g, x-1, y, fill, boundary);
            boundaryFill4 (g, x, y+1, fill, boundary);
            boundaryFill4 (g, x , y-1, fill, boundary);
        }
    }
}