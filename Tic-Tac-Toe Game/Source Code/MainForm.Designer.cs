using System.Drawing;

namespace Tic_Tac_Toe_Game
{
    partial class MainForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.btnFriendOption = new System.Windows.Forms.Button();
            this.btnComputerOption = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnFriendOption
            // 
            this.btnFriendOption.BackColor = System.Drawing.Color.Black;
            this.btnFriendOption.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnFriendOption.Font = new System.Drawing.Font("OCR A Extended", 20F);
            this.btnFriendOption.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(220)))), ((int)(((byte)(0)))));
            this.btnFriendOption.Location = new System.Drawing.Point(719, 397);
            this.btnFriendOption.Name = "btnFriendOption";
            this.btnFriendOption.Size = new System.Drawing.Size(266, 86);
            this.btnFriendOption.TabIndex = 0;
            this.btnFriendOption.Tag = "Friend";
            this.btnFriendOption.Text = "Friend";
            this.btnFriendOption.UseVisualStyleBackColor = false;
            this.btnFriendOption.Click += new System.EventHandler(this.btnOption_Click);
            // 
            // btnComputerOption
            // 
            this.btnComputerOption.BackColor = System.Drawing.Color.Black;
            this.btnComputerOption.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnComputerOption.Font = new System.Drawing.Font("OCR A Extended", 20F);
            this.btnComputerOption.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(220)))), ((int)(((byte)(0)))));
            this.btnComputerOption.Location = new System.Drawing.Point(236, 397);
            this.btnComputerOption.Name = "btnComputerOption";
            this.btnComputerOption.Size = new System.Drawing.Size(266, 86);
            this.btnComputerOption.TabIndex = 1;
            this.btnComputerOption.Tag = "Computer";
            this.btnComputerOption.Text = "Computer";
            this.btnComputerOption.UseVisualStyleBackColor = false;
            this.btnComputerOption.Click += new System.EventHandler(this.btnOption_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.Color.Transparent;
            this.label5.Font = new System.Drawing.Font("OCR A Extended", 13F);
            this.label5.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(220)))), ((int)(((byte)(0)))));
            this.label5.Location = new System.Drawing.Point(40, 748);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(163, 19);
            this.label5.TabIndex = 20;
            this.label5.Text = "By Abdullah <3";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1229, 819);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.btnComputerOption);
            this.Controls.Add(this.btnFriendOption);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "MainForm";
            this.Text = "Tick-Tac-Toe";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.MainForm_Paint);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnFriendOption;
        private System.Windows.Forms.Button btnComputerOption;
        private System.Windows.Forms.Label label5;
    }
}