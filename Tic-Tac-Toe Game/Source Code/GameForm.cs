using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using Tic_Tac_Toe_Game.Properties;

namespace Tic_Tac_Toe_Game
{
    public partial class GameForm : Form
    {
        MainForm mainForm; // to use when going back to main form
        public GameForm(String Player2, MainForm form)
        {
            InitializeComponent();
            mainForm = form;
            this.AutoScaleMode = AutoScaleMode.None;
            this.Font = new Font(this.Font.FontFamily, this.Font.Size, GraphicsUnit.Pixel);
            this.MaximizeBox = false;

            pictureBox1.Tag = enBoxesNumbers.eBox1;
            pictureBox2.Tag = enBoxesNumbers.eBox2;
            pictureBox3.Tag = enBoxesNumbers.eBox3;
            pictureBox4.Tag = enBoxesNumbers.eBox4;
            pictureBox5.Tag = enBoxesNumbers.eBox5;
            pictureBox6.Tag = enBoxesNumbers.eBox6;
            pictureBox7.Tag = enBoxesNumbers.eBox7;
            pictureBox8.Tag = enBoxesNumbers.eBox8;
            pictureBox9.Tag = enBoxesNumbers.eBox9;

            if (Player2 == "Computer")
                IsPlayer2Computer = true;
        }


        // to work with bitwise operations
        enum enBoxesNumbers { eBox1 = 1, eBox2 = 2, eBox3 = 4, eBox4 = 8, eBox5 = 16, eBox6 = 32, eBox7 = 64, eBox8 = 128, eBox9 = 256 };
        private enBoxesNumbers Player1Boxes = 0;
        private enBoxesNumbers Player2Boxes = 0;
        private enBoxesNumbers TakenBoxes = 0;
        private enBoxesNumbers[] WiningCombos = {

            (enBoxesNumbers.eBox1 | enBoxesNumbers.eBox2 | enBoxesNumbers.eBox3),
            (enBoxesNumbers.eBox4 | enBoxesNumbers.eBox5 | enBoxesNumbers.eBox6),
            (enBoxesNumbers.eBox7 | enBoxesNumbers.eBox8 | enBoxesNumbers.eBox9),
            (enBoxesNumbers.eBox1 | enBoxesNumbers.eBox4 | enBoxesNumbers.eBox7),
            (enBoxesNumbers.eBox2 | enBoxesNumbers.eBox5 | enBoxesNumbers.eBox8),
            (enBoxesNumbers.eBox3 | enBoxesNumbers.eBox6 | enBoxesNumbers.eBox9),
            (enBoxesNumbers.eBox3 | enBoxesNumbers.eBox5 | enBoxesNumbers.eBox7),
            (enBoxesNumbers.eBox1 | enBoxesNumbers.eBox5 | enBoxesNumbers.eBox9)
        };
       

        private int Turn = 0; // to control player turn and which picture to show
        private int Rounds = 1;
        bool IsPlayer2Computer = false;

        private void plBoxes_Paint(object sender, PaintEventArgs e)
        {
            Pen pen = new Pen(Color.FromArgb(255, 220, 0), 6);
            pen.StartCap = System.Drawing.Drawing2D.LineCap.Flat;
            pen.EndCap = System.Drawing.Drawing2D.LineCap.Flat;

            // using panel-relative coordinates to draw inside the panel itself not the whole form
            int w = plBoxes.Width;
            int h = plBoxes.Height;

            // vertical lines
            e.Graphics.DrawLine(pen, w / 3, 0, w / 3, h);
            e.Graphics.DrawLine(pen, 2 * w / 3, 0, 2 * w / 3, h);

            // horizontal lines
            e.Graphics.DrawLine(pen, 0, h / 3, w, h / 3);
            e.Graphics.DrawLine(pen, 0, 2 * h / 3, w, 2 * h / 3);

            pen.Dispose();
        }

        private void SwitchPicBox(PictureBox ClickedBox)
        {
           
            ClickedBox.Image = Turn % 2 == 0 ? Resources.x1 : Resources.o2;
            TakenBoxes |= (enBoxesNumbers)ClickedBox.Tag;

            if (Turn % 2 == 0)
            {
                Player1Boxes |= (enBoxesNumbers)ClickedBox.Tag;
            }
            else
            {
                Player2Boxes |= (enBoxesNumbers)ClickedBox.Tag;
            }

            Turn++;
            lblCurrentPlayer.Text = Turn % 2 == 0 ? "Player 1" : "Player 2";

        }

        private bool CheckWinCombo(enBoxesNumbers PlayerBoxes)
        {
            if ((PlayerBoxes & WiningCombos[0]) == WiningCombos[0])
            {
                pictureBox1.BackColor = Color.Green;
                pictureBox2.BackColor = Color.Green;
                pictureBox3.BackColor = Color.Green;
                return true;
            }
            else if ((PlayerBoxes & WiningCombos[1]) == WiningCombos[1])
            {
                pictureBox4.BackColor = Color.Green;
                pictureBox5.BackColor = Color.Green;
                pictureBox6.BackColor = Color.Green;
                return true;
            }
            else if ((PlayerBoxes & WiningCombos[2]) == WiningCombos[2])
            {
                pictureBox7.BackColor = Color.Green;
                pictureBox8.BackColor = Color.Green;
                pictureBox9.BackColor = Color.Green;
                return true;
            }
            else if ((PlayerBoxes & WiningCombos[3]) == WiningCombos[3])
            {
                pictureBox1.BackColor = Color.Green;
                pictureBox4.BackColor = Color.Green;
                pictureBox7.BackColor = Color.Green;
                return true;
            }
            else if ((PlayerBoxes & WiningCombos[4]) == WiningCombos[4])
            {
                pictureBox2.BackColor = Color.Green;
                pictureBox5.BackColor = Color.Green;
                pictureBox8.BackColor = Color.Green;
                return true;
            }
            else if ((PlayerBoxes & WiningCombos[5]) == WiningCombos[5])
            {
                pictureBox3.BackColor = Color.Green;
                pictureBox6.BackColor = Color.Green;
                pictureBox9.BackColor = Color.Green;
                return true;
            }
            else if ((PlayerBoxes & WiningCombos[6]) == WiningCombos[6])
            {
                pictureBox3.BackColor = Color.Green;
                pictureBox5.BackColor = Color.Green;
                pictureBox7.BackColor = Color.Green;
                return true;
            }
            else if ((PlayerBoxes & WiningCombos[7]) == WiningCombos[7])
            {
                pictureBox1.BackColor = Color.Green;
                pictureBox5.BackColor = Color.Green;
                pictureBox9.BackColor = Color.Green;
                return true;
            }

            return false;
        }

        private bool CheckWinner()
        {

            int WinnerPlayer = CheckWinCombo(Player1Boxes) ? 1 : CheckWinCombo(Player2Boxes) ? 2 : 0;
            if (WinnerPlayer > 0)
            {
                lblWinner.Text = $"Player {WinnerPlayer}";
                MessageBox.Show($"Player {WinnerPlayer} Won The Round!!!", "Round Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
                plBoxes.Enabled = false;
                btnNewRound.ForeColor = Color.Green;
                return true;
            }
            else if (Turn == 9)
            {
                lblWinner.Text = "Draw";
                MessageBox.Show("No Winner, it is a Draw!", "Draw", MessageBoxButtons.OK, MessageBoxIcon.Information);
                plBoxes.Enabled = false;
                btnNewRound.ForeColor = Color.Green;
                return true;
            }

            return false;
        }

        private void ComputerTurn()
        {
            // to prepare a list with not taken boxes
            List<PictureBox> BoxesForComputer = new List<PictureBox>();
            foreach (Control ctrl in plBoxes.Controls)
            {
                if (ctrl is PictureBox && ((TakenBoxes & (enBoxesNumbers)ctrl.Tag) == 0))
                {
                    PictureBox temp = (PictureBox)ctrl;
                    BoxesForComputer.Add(temp);
                }
            }

            // here to make the computer chose a box from the list
            PictureBox ComputerChoice = null;
            Random rnd = new Random();
            int Index = rnd.Next(BoxesForComputer.Count);
            ComputerChoice = BoxesForComputer[Index];

            // then to update the game screen and players data
            ComputerChoice.Image = Resources.o2;
            TakenBoxes |= (enBoxesNumbers)ComputerChoice.Tag;
            Player2Boxes |= (enBoxesNumbers)ComputerChoice.Tag;
            Turn++;
            lblCurrentPlayer.Text = "Player 1";
        }



        // one click handler for all 9 picture boxes
        private void PictureBoxes_Click(object sender, EventArgs e)
        {
            PictureBox ClickedBox = ((PictureBox)sender);

            if (ClickedBox == null)
                return;


            if (((enBoxesNumbers)ClickedBox.Tag & TakenBoxes ) != 0)
            {
                MessageBox.Show("Wrong Choice! Place Already Taken", "Wrong!", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }

            SwitchPicBox(ClickedBox);
            if (CheckWinner())
                return;


            if (IsPlayer2Computer && Turn % 2 != 0)
            {
                ComputerTurn();
                CheckWinner();
            }
        }



        private void pbBackBtn_Click(object sender, EventArgs e)
        {
            mainForm.Show();
            this.Close();
        }

        private void btnNewRound_Click(object sender, EventArgs e)
        {
            foreach (PictureBox pb in plBoxes.Controls)
            {
                pb.Image = Resources.Q;
                pb.BackColor = Color.Transparent;
            }

            TakenBoxes = 0;
            Player1Boxes = 0;
            Player2Boxes = 0;

            lblCurrentPlayer.Text = "Player 1";
            lblWinner.Text = "-";
            Rounds++;
            Turn = 0;
            lblRoundCounter.Text = Rounds.ToString();
            plBoxes.Enabled = true;
            btnNewRound.ForeColor = Color.FromArgb(255, 220, 0);
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

    }
}
