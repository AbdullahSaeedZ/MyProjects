namespace ToDoList
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
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.checkedListBox1 = new System.Windows.Forms.CheckedListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btnAddTask = new System.Windows.Forms.Button();
            this.tbTaskTyping = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.lblPendingTasks = new System.Windows.Forms.Label();
            this.lblCompletedTasks = new System.Windows.Forms.Label();
            this.btnRemoveOneTask = new System.Windows.Forms.Button();
            this.btnUnCheckAll = new System.Windows.Forms.Button();
            this.btnRemoveAllTasks = new System.Windows.Forms.Button();
            this.btnCheckAll = new System.Windows.Forms.Button();
            this.btnAddCategory = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.btnDeleteCategory = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // comboBox1
            // 
            this.comboBox1.BackColor = System.Drawing.SystemColors.Info;
            this.comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F);
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(793, 322);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(414, 46);
            this.comboBox1.Sorted = true;
            this.comboBox1.TabIndex = 2;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // checkedListBox1
            // 
            this.checkedListBox1.BackColor = System.Drawing.SystemColors.Info;
            this.checkedListBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.8F);
            this.checkedListBox1.FormattingEnabled = true;
            this.checkedListBox1.Location = new System.Drawing.Point(12, 159);
            this.checkedListBox1.Name = "checkedListBox1";
            this.checkedListBox1.Size = new System.Drawing.Size(722, 676);
            this.checkedListBox1.TabIndex = 1;
            this.checkedListBox1.ItemCheck += new System.Windows.Forms.ItemCheckEventHandler(this.checkedListBox1_ItemCheck);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Comic Sans MS", 18F, System.Drawing.FontStyle.Bold);
            this.label1.ForeColor = System.Drawing.Color.Black;
            this.label1.Location = new System.Drawing.Point(786, 278);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(266, 41);
            this.label1.TabIndex = 2;
            this.label1.Text = "Select Category:";
            // 
            // btnAddTask
            // 
            this.btnAddTask.BackColor = System.Drawing.SystemColors.Control;
            this.btnAddTask.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnAddTask.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.btnAddTask.ForeColor = System.Drawing.Color.Black;
            this.btnAddTask.Location = new System.Drawing.Point(793, 202);
            this.btnAddTask.Name = "btnAddTask";
            this.btnAddTask.Size = new System.Drawing.Size(191, 49);
            this.btnAddTask.TabIndex = 1;
            this.btnAddTask.Text = "Add Task";
            this.btnAddTask.UseVisualStyleBackColor = false;
            this.btnAddTask.Click += new System.EventHandler(this.btnAddTask_Click);
            // 
            // tbTaskTyping
            // 
            this.tbTaskTyping.BackColor = System.Drawing.SystemColors.Info;
            this.tbTaskTyping.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F);
            this.tbTaskTyping.Location = new System.Drawing.Point(793, 160);
            this.tbTaskTyping.Name = "tbTaskTyping";
            this.tbTaskTyping.Size = new System.Drawing.Size(414, 36);
            this.tbTaskTyping.TabIndex = 0;
            this.tbTaskTyping.Text = "Type Your Task Here";
            this.tbTaskTyping.Enter += new System.EventHandler(this.tbTaskTyping_Enter);
            this.tbTaskTyping.Leave += new System.EventHandler(this.tbTaskTyping_Leave);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("Comic Sans MS", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.Black;
            this.label2.Location = new System.Drawing.Point(12, 74);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(235, 41);
            this.label2.TabIndex = 5;
            this.label2.Text = "Pending Tasks:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Font = new System.Drawing.Font("Comic Sans MS", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.Black;
            this.label3.Location = new System.Drawing.Point(12, 21);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(276, 41);
            this.label3.TabIndex = 6;
            this.label3.Text = "Completed Tasks:";
            // 
            // lblPendingTasks
            // 
            this.lblPendingTasks.AutoSize = true;
            this.lblPendingTasks.BackColor = System.Drawing.Color.Transparent;
            this.lblPendingTasks.Font = new System.Drawing.Font("Comic Sans MS", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPendingTasks.ForeColor = System.Drawing.Color.Black;
            this.lblPendingTasks.Location = new System.Drawing.Point(318, 74);
            this.lblPendingTasks.Name = "lblPendingTasks";
            this.lblPendingTasks.Size = new System.Drawing.Size(36, 41);
            this.lblPendingTasks.TabIndex = 7;
            this.lblPendingTasks.Text = "0";
            // 
            // lblCompletedTasks
            // 
            this.lblCompletedTasks.AutoSize = true;
            this.lblCompletedTasks.BackColor = System.Drawing.Color.Transparent;
            this.lblCompletedTasks.Font = new System.Drawing.Font("Comic Sans MS", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCompletedTasks.ForeColor = System.Drawing.Color.Black;
            this.lblCompletedTasks.Location = new System.Drawing.Point(318, 21);
            this.lblCompletedTasks.Name = "lblCompletedTasks";
            this.lblCompletedTasks.Size = new System.Drawing.Size(36, 41);
            this.lblCompletedTasks.TabIndex = 8;
            this.lblCompletedTasks.Text = "0";
            // 
            // btnRemoveOneTask
            // 
            this.btnRemoveOneTask.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnRemoveOneTask.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.btnRemoveOneTask.ForeColor = System.Drawing.Color.Black;
            this.btnRemoveOneTask.Location = new System.Drawing.Point(793, 477);
            this.btnRemoveOneTask.Name = "btnRemoveOneTask";
            this.btnRemoveOneTask.Size = new System.Drawing.Size(414, 73);
            this.btnRemoveOneTask.TabIndex = 9;
            this.btnRemoveOneTask.Text = "Rmove Selected Task";
            this.btnRemoveOneTask.UseVisualStyleBackColor = true;
            this.btnRemoveOneTask.Click += new System.EventHandler(this.btnRemoveOneTask_Click);
            // 
            // btnUnCheckAll
            // 
            this.btnUnCheckAll.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnUnCheckAll.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.btnUnCheckAll.ForeColor = System.Drawing.Color.Black;
            this.btnUnCheckAll.Location = new System.Drawing.Point(793, 667);
            this.btnUnCheckAll.Name = "btnUnCheckAll";
            this.btnUnCheckAll.Size = new System.Drawing.Size(414, 73);
            this.btnUnCheckAll.TabIndex = 10;
            this.btnUnCheckAll.Tag = "false";
            this.btnUnCheckAll.Text = "Uncheck All";
            this.btnUnCheckAll.UseVisualStyleBackColor = true;
            this.btnUnCheckAll.Click += new System.EventHandler(this.btnCheckOruncheckAll_Click);
            // 
            // btnRemoveAllTasks
            // 
            this.btnRemoveAllTasks.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnRemoveAllTasks.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.btnRemoveAllTasks.ForeColor = System.Drawing.Color.Black;
            this.btnRemoveAllTasks.Location = new System.Drawing.Point(793, 762);
            this.btnRemoveAllTasks.Name = "btnRemoveAllTasks";
            this.btnRemoveAllTasks.Size = new System.Drawing.Size(414, 73);
            this.btnRemoveAllTasks.TabIndex = 11;
            this.btnRemoveAllTasks.Text = "Clear All Tasks";
            this.btnRemoveAllTasks.UseVisualStyleBackColor = true;
            this.btnRemoveAllTasks.Click += new System.EventHandler(this.btnRemoveAllTasks_Click);
            // 
            // btnCheckAll
            // 
            this.btnCheckAll.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnCheckAll.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.btnCheckAll.ForeColor = System.Drawing.Color.Black;
            this.btnCheckAll.Location = new System.Drawing.Point(793, 573);
            this.btnCheckAll.Name = "btnCheckAll";
            this.btnCheckAll.Size = new System.Drawing.Size(414, 73);
            this.btnCheckAll.TabIndex = 12;
            this.btnCheckAll.Tag = "true";
            this.btnCheckAll.Text = "Check All";
            this.btnCheckAll.UseVisualStyleBackColor = true;
            this.btnCheckAll.Click += new System.EventHandler(this.btnCheckOruncheckAll_Click);
            // 
            // btnAddCategory
            // 
            this.btnAddCategory.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnAddCategory.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.btnAddCategory.ForeColor = System.Drawing.Color.Black;
            this.btnAddCategory.Location = new System.Drawing.Point(793, 374);
            this.btnAddCategory.Name = "btnAddCategory";
            this.btnAddCategory.Size = new System.Drawing.Size(201, 55);
            this.btnAddCategory.TabIndex = 3;
            this.btnAddCategory.Text = "Add";
            this.btnAddCategory.UseVisualStyleBackColor = true;
            this.btnAddCategory.Click += new System.EventHandler(this.btnAddCategory_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Comic Sans MS", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.White;
            this.label6.Location = new System.Drawing.Point(25, 21);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(0, 41);
            this.label6.TabIndex = 14;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.Font = new System.Drawing.Font("Comic Sans MS", 40.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.Info;
            this.label4.Location = new System.Drawing.Point(777, 9);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(384, 94);
            this.label4.TabIndex = 15;
            this.label4.Text = "To Do List";
            // 
            // btnDeleteCategory
            // 
            this.btnDeleteCategory.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnDeleteCategory.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.btnDeleteCategory.ForeColor = System.Drawing.Color.Black;
            this.btnDeleteCategory.Location = new System.Drawing.Point(1006, 374);
            this.btnDeleteCategory.Name = "btnDeleteCategory";
            this.btnDeleteCategory.Size = new System.Drawing.Size(201, 55);
            this.btnDeleteCategory.TabIndex = 16;
            this.btnDeleteCategory.Text = "Delete";
            this.btnDeleteCategory.UseVisualStyleBackColor = true;
            this.btnDeleteCategory.Click += new System.EventHandler(this.btnDeleteCategory_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1238, 871);
            this.Controls.Add(this.btnDeleteCategory);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.btnAddCategory);
            this.Controls.Add(this.btnCheckAll);
            this.Controls.Add(this.btnRemoveAllTasks);
            this.Controls.Add(this.btnUnCheckAll);
            this.Controls.Add(this.btnRemoveOneTask);
            this.Controls.Add(this.lblCompletedTasks);
            this.Controls.Add(this.lblPendingTasks);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.tbTaskTyping);
            this.Controls.Add(this.btnAddTask);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.checkedListBox1);
            this.Controls.Add(this.comboBox1);
            this.ForeColor = System.Drawing.SystemColors.Info;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "MainForm";
            this.Text = "To Do List";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.CheckedListBox checkedListBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnAddTask;
        private System.Windows.Forms.TextBox tbTaskTyping;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label lblPendingTasks;
        private System.Windows.Forms.Label lblCompletedTasks;
        private System.Windows.Forms.Button btnRemoveOneTask;
        private System.Windows.Forms.Button btnUnCheckAll;
        private System.Windows.Forms.Button btnRemoveAllTasks;
        private System.Windows.Forms.Button btnCheckAll;
        private System.Windows.Forms.Button btnAddCategory;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btnDeleteCategory;
    }
}

