using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tic_Tac_Toe_Game
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            this.AutoScaleMode = AutoScaleMode.None;
            this.Font = new Font(this.Font.FontFamily, this.Font.Size, GraphicsUnit.Pixel);
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;


        }

        private void MainForm_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            using (Font f = new Font("OCR A Extended", 48, FontStyle.Regular, GraphicsUnit.Pixel))
            using (Brush b = new SolidBrush(Color.FromArgb(255, 220, 0)))
            {
                e.Graphics.DrawString("Choose Your Opponent", f, b, new PointF(150, 200));
            }
        }

        private void btnOption_Click(object sender, EventArgs e)
        {
            GameForm temp = new GameForm(((Button)sender).Tag.ToString() , this);
            temp.Show();
            this.Hide();
            
        }

      
    }
}
