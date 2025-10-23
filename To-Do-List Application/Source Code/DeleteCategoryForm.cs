using System;
using System.Collections.Generic;
using System.Windows.Forms;
using static ToDoList.MainForm;

namespace ToDoList
{
    public partial class DeleteCategoryForm : Form
    {
        public DeleteCategoryForm()
        {
            InitializeComponent();
        }

        private void btnDeleteCategory_Click(object sender, EventArgs e)
        {

            if (comboBox1.SelectedItem == null)
            {
                MessageBox.Show("Choose Category First!", "Select Category", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                if (MessageBox.Show("Are You Sure To Delete This Category?", "Confirm", MessageBoxButtons.OKCancel, MessageBoxIcon.Question) == DialogResult.OK)
                {
                    string KeyToDelete = comboBox1.SelectedItem.ToString();
                    MainForm.TasksCategories.Remove(KeyToDelete);
                }

                this.Close();
            }
        }

        private void comboBox1_Click(object sender, EventArgs e)
        {
            comboBox1.Items.Clear();

            foreach (string key in MainForm.TasksCategories.Keys)
            {
                comboBox1.Items.Add(key);
            }
        }
    }
}
