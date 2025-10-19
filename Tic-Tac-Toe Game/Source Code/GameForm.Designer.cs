namespace Tic_Tac_Toe_Game
{
    partial class GameForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(GameForm));
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.btnNewRound = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.lblCurrentPlayer = new System.Windows.Forms.Label();
            this.lblWinner = new System.Windows.Forms.Label();
            this.lblRoundCounter = new System.Windows.Forms.Label();
            this.pictureBox7 = new System.Windows.Forms.PictureBox();
            this.pictureBox4 = new System.Windows.Forms.PictureBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.pictureBox5 = new System.Windows.Forms.PictureBox();
            this.pictureBox8 = new System.Windows.Forms.PictureBox();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.pictureBox6 = new System.Windows.Forms.PictureBox();
            this.pictureBox9 = new System.Windows.Forms.PictureBox();
            this.plBoxes = new System.Windows.Forms.Panel();
            this.label5 = new System.Windows.Forms.Label();
            this.pbBackBtn = new System.Windows.Forms.PictureBox();
            this.label6 = new System.Windows.Forms.Label();
            this.pictureBox10 = new System.Windows.Forms.PictureBox();
            this.pictureBox11 = new System.Windows.Forms.PictureBox();
            this.label7 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox9)).BeginInit();
            this.plBoxes.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbBackBtn)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox10)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox11)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("OCR A Extended", 28F);
            this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(220)))), ((int)(((byte)(0)))));
            this.label1.Location = new System.Drawing.Point(972, 259);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(162, 49);
            this.label1.TabIndex = 0;
            this.label1.Text = "Turn:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("OCR A Extended", 28F);
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(220)))), ((int)(((byte)(0)))));
            this.label2.Location = new System.Drawing.Point(972, 384);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(218, 49);
            this.label2.TabIndex = 1;
            this.label2.Text = "Winner:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Font = new System.Drawing.Font("OCR A Extended", 28F);
            this.label3.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(220)))), ((int)(((byte)(0)))));
            this.label3.Location = new System.Drawing.Point(972, 520);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(442, 49);
            this.label3.TabIndex = 2;
            this.label3.Text = "Rounds Counter:";
            // 
            // btnNewRound
            // 
            this.btnNewRound.BackColor = System.Drawing.Color.Black;
            this.btnNewRound.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnNewRound.Font = new System.Drawing.Font("OCR A Extended", 28F);
            this.btnNewRound.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(220)))), ((int)(((byte)(0)))));
            this.btnNewRound.Location = new System.Drawing.Point(966, 627);
            this.btnNewRound.Name = "btnNewRound";
            this.btnNewRound.Size = new System.Drawing.Size(520, 77);
            this.btnNewRound.TabIndex = 3;
            this.btnNewRound.Text = "Start New Round";
            this.btnNewRound.UseVisualStyleBackColor = false;
            this.btnNewRound.Click += new System.EventHandler(this.btnNewRound_Click);
            // 
            // btnExit
            // 
            this.btnExit.BackColor = System.Drawing.Color.Black;
            this.btnExit.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnExit.Font = new System.Drawing.Font("OCR A Extended", 28F);
            this.btnExit.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(220)))), ((int)(((byte)(0)))));
            this.btnExit.Location = new System.Drawing.Point(966, 760);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(520, 77);
            this.btnExit.TabIndex = 4;
            this.btnExit.Text = "Exit Game";
            this.btnExit.UseVisualStyleBackColor = false;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.Font = new System.Drawing.Font("OCR A Extended", 70.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(220)))), ((int)(((byte)(0)))));
            this.label4.Location = new System.Drawing.Point(360, 24);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(844, 122);
            this.label4.TabIndex = 5;
            this.label4.Text = "Tic-Tac-Toe";
            // 
            // lblCurrentPlayer
            // 
            this.lblCurrentPlayer.AutoSize = true;
            this.lblCurrentPlayer.BackColor = System.Drawing.Color.Transparent;
            this.lblCurrentPlayer.Font = new System.Drawing.Font("OCR A Extended", 25F);
            this.lblCurrentPlayer.ForeColor = System.Drawing.Color.OldLace;
            this.lblCurrentPlayer.Location = new System.Drawing.Point(1195, 264);
            this.lblCurrentPlayer.Name = "lblCurrentPlayer";
            this.lblCurrentPlayer.Size = new System.Drawing.Size(219, 43);
            this.lblCurrentPlayer.TabIndex = 6;
            this.lblCurrentPlayer.Text = "Player 1";
            // 
            // lblWinner
            // 
            this.lblWinner.AutoSize = true;
            this.lblWinner.BackColor = System.Drawing.Color.Transparent;
            this.lblWinner.Font = new System.Drawing.Font("OCR A Extended", 25F);
            this.lblWinner.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.lblWinner.Location = new System.Drawing.Point(1183, 389);
            this.lblWinner.Name = "lblWinner";
            this.lblWinner.Size = new System.Drawing.Size(294, 43);
            this.lblWinner.TabIndex = 7;
            this.lblWinner.Text = "In Progress";
            // 
            // lblRoundCounter
            // 
            this.lblRoundCounter.AutoSize = true;
            this.lblRoundCounter.BackColor = System.Drawing.Color.Transparent;
            this.lblRoundCounter.Font = new System.Drawing.Font("OCR A Extended", 30F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblRoundCounter.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.lblRoundCounter.Location = new System.Drawing.Point(1401, 517);
            this.lblRoundCounter.Name = "lblRoundCounter";
            this.lblRoundCounter.Size = new System.Drawing.Size(52, 52);
            this.lblRoundCounter.TabIndex = 8;
            this.lblRoundCounter.Text = "1";
            // 
            // pictureBox7
            // 
            this.pictureBox7.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox7.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox7.Image = global::Tic_Tac_Toe_Game.Properties.Resources.Q;
            this.pictureBox7.Location = new System.Drawing.Point(17, 5);
            this.pictureBox7.Name = "pictureBox7";
            this.pictureBox7.Size = new System.Drawing.Size(177, 106);
            this.pictureBox7.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox7.TabIndex = 9;
            this.pictureBox7.TabStop = false;
            this.pictureBox7.Tag = "";
            this.pictureBox7.Click += new System.EventHandler(this.PictureBoxes_Click);
            // 
            // pictureBox4
            // 
            this.pictureBox4.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox4.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox4.Image = global::Tic_Tac_Toe_Game.Properties.Resources.Q;
            this.pictureBox4.Location = new System.Drawing.Point(17, 163);
            this.pictureBox4.Name = "pictureBox4";
            this.pictureBox4.Size = new System.Drawing.Size(177, 106);
            this.pictureBox4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox4.TabIndex = 10;
            this.pictureBox4.TabStop = false;
            this.pictureBox4.Tag = "";
            this.pictureBox4.Click += new System.EventHandler(this.PictureBoxes_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(17, 311);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(177, 106);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 11;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Tag = "";
            this.pictureBox1.Click += new System.EventHandler(this.PictureBoxes_Click);
            // 
            // pictureBox2
            // 
            this.pictureBox2.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox2.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox2.Image")));
            this.pictureBox2.Location = new System.Drawing.Point(291, 311);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(177, 106);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox2.TabIndex = 14;
            this.pictureBox2.TabStop = false;
            this.pictureBox2.Tag = "";
            this.pictureBox2.Click += new System.EventHandler(this.PictureBoxes_Click);
            // 
            // pictureBox5
            // 
            this.pictureBox5.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox5.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox5.Image = global::Tic_Tac_Toe_Game.Properties.Resources.Q;
            this.pictureBox5.Location = new System.Drawing.Point(291, 163);
            this.pictureBox5.Name = "pictureBox5";
            this.pictureBox5.Size = new System.Drawing.Size(177, 106);
            this.pictureBox5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox5.TabIndex = 13;
            this.pictureBox5.TabStop = false;
            this.pictureBox5.Tag = "";
            this.pictureBox5.Click += new System.EventHandler(this.PictureBoxes_Click);
            // 
            // pictureBox8
            // 
            this.pictureBox8.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox8.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox8.Image = global::Tic_Tac_Toe_Game.Properties.Resources.Q;
            this.pictureBox8.Location = new System.Drawing.Point(291, 5);
            this.pictureBox8.Name = "pictureBox8";
            this.pictureBox8.Size = new System.Drawing.Size(177, 106);
            this.pictureBox8.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox8.TabIndex = 12;
            this.pictureBox8.TabStop = false;
            this.pictureBox8.Tag = "";
            this.pictureBox8.Click += new System.EventHandler(this.PictureBoxes_Click);
            // 
            // pictureBox3
            // 
            this.pictureBox3.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox3.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox3.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox3.Image")));
            this.pictureBox3.Location = new System.Drawing.Point(580, 311);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(177, 106);
            this.pictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox3.TabIndex = 17;
            this.pictureBox3.TabStop = false;
            this.pictureBox3.Tag = "";
            this.pictureBox3.Click += new System.EventHandler(this.PictureBoxes_Click);
            // 
            // pictureBox6
            // 
            this.pictureBox6.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox6.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox6.Image = global::Tic_Tac_Toe_Game.Properties.Resources.Q;
            this.pictureBox6.Location = new System.Drawing.Point(580, 163);
            this.pictureBox6.Name = "pictureBox6";
            this.pictureBox6.Size = new System.Drawing.Size(177, 106);
            this.pictureBox6.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox6.TabIndex = 16;
            this.pictureBox6.TabStop = false;
            this.pictureBox6.Tag = "";
            this.pictureBox6.Click += new System.EventHandler(this.PictureBoxes_Click);
            // 
            // pictureBox9
            // 
            this.pictureBox9.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox9.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox9.Image = global::Tic_Tac_Toe_Game.Properties.Resources.Q;
            this.pictureBox9.Location = new System.Drawing.Point(580, 5);
            this.pictureBox9.Name = "pictureBox9";
            this.pictureBox9.Size = new System.Drawing.Size(177, 106);
            this.pictureBox9.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox9.TabIndex = 15;
            this.pictureBox9.TabStop = false;
            this.pictureBox9.Tag = "";
            this.pictureBox9.Click += new System.EventHandler(this.PictureBoxes_Click);
            // 
            // plBoxes
            // 
            this.plBoxes.BackColor = System.Drawing.Color.Transparent;
            this.plBoxes.Controls.Add(this.pictureBox3);
            this.plBoxes.Controls.Add(this.pictureBox6);
            this.plBoxes.Controls.Add(this.pictureBox9);
            this.plBoxes.Controls.Add(this.pictureBox2);
            this.plBoxes.Controls.Add(this.pictureBox5);
            this.plBoxes.Controls.Add(this.pictureBox8);
            this.plBoxes.Controls.Add(this.pictureBox1);
            this.plBoxes.Controls.Add(this.pictureBox4);
            this.plBoxes.Controls.Add(this.pictureBox7);
            this.plBoxes.Location = new System.Drawing.Point(50, 287);
            this.plBoxes.Name = "plBoxes";
            this.plBoxes.Size = new System.Drawing.Size(770, 428);
            this.plBoxes.TabIndex = 18;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.Color.Transparent;
            this.label5.Font = new System.Drawing.Font("OCR A Extended", 13F);
            this.label5.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(220)))), ((int)(((byte)(0)))));
            this.label5.Location = new System.Drawing.Point(12, 863);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(192, 24);
            this.label5.TabIndex = 19;
            this.label5.Text = "By Abdullah <3";
            // 
            // pbBackBtn
            // 
            this.pbBackBtn.BackColor = System.Drawing.Color.Transparent;
            this.pbBackBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pbBackBtn.Image = ((System.Drawing.Image)(resources.GetObject("pbBackBtn.Image")));
            this.pbBackBtn.Location = new System.Drawing.Point(12, 24);
            this.pbBackBtn.Name = "pbBackBtn";
            this.pbBackBtn.Size = new System.Drawing.Size(76, 74);
            this.pbBackBtn.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbBackBtn.TabIndex = 20;
            this.pbBackBtn.TabStop = false;
            this.pbBackBtn.Click += new System.EventHandler(this.pbBackBtn_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.Color.Transparent;
            this.label6.Font = new System.Drawing.Font("OCR A Extended", 15F);
            this.label6.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(220)))), ((int)(((byte)(0)))));
            this.label6.Location = new System.Drawing.Point(84, 219);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(132, 26);
            this.label6.TabIndex = 21;
            this.label6.Text = "Player 1";
            // 
            // pictureBox10
            // 
            this.pictureBox10.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox10.Image = global::Tic_Tac_Toe_Game.Properties.Resources.x1;
            this.pictureBox10.Location = new System.Drawing.Point(222, 215);
            this.pictureBox10.Name = "pictureBox10";
            this.pictureBox10.Size = new System.Drawing.Size(38, 36);
            this.pictureBox10.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox10.TabIndex = 22;
            this.pictureBox10.TabStop = false;
            // 
            // pictureBox11
            // 
            this.pictureBox11.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox11.Image = global::Tic_Tac_Toe_Game.Properties.Resources.o2;
            this.pictureBox11.Location = new System.Drawing.Point(715, 215);
            this.pictureBox11.Name = "pictureBox11";
            this.pictureBox11.Size = new System.Drawing.Size(38, 36);
            this.pictureBox11.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox11.TabIndex = 24;
            this.pictureBox11.TabStop = false;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.Color.Transparent;
            this.label7.Font = new System.Drawing.Font("OCR A Extended", 15F);
            this.label7.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(220)))), ((int)(((byte)(0)))));
            this.label7.Location = new System.Drawing.Point(577, 219);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(132, 26);
            this.label7.TabIndex = 23;
            this.label7.Text = "Player 2";
            // 
            // GameForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(1522, 898);
            this.Controls.Add(this.pictureBox11);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.pictureBox10);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.pbBackBtn);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.lblRoundCounter);
            this.Controls.Add(this.lblWinner);
            this.Controls.Add(this.lblCurrentPlayer);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.btnNewRound);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.plBoxes);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "GameForm";
            this.Text = "Tick-Tac-Toe";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.GameForm_Paint);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox9)).EndInit();
            this.plBoxes.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pbBackBtn)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox10)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox11)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnNewRound;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label lblCurrentPlayer;
        private System.Windows.Forms.Label lblWinner;
        private System.Windows.Forms.Label lblRoundCounter;
        private System.Windows.Forms.PictureBox pictureBox7;
        private System.Windows.Forms.PictureBox pictureBox4;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.PictureBox pictureBox5;
        private System.Windows.Forms.PictureBox pictureBox8;
        private System.Windows.Forms.PictureBox pictureBox3;
        private System.Windows.Forms.PictureBox pictureBox6;
        private System.Windows.Forms.PictureBox pictureBox9;
        private System.Windows.Forms.Panel plBoxes;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.PictureBox pbBackBtn;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.PictureBox pictureBox10;
        private System.Windows.Forms.PictureBox pictureBox11;
        private System.Windows.Forms.Label label7;
    }
}

