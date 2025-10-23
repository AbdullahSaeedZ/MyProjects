using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using static ToDoList.MainForm;

namespace ToDoList
{
    public partial class AddCategoryForm : Form
    {
        public AddCategoryForm()
        {
            InitializeComponent();
           
        }

        private void btnAddCategory_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(tbCategoryName.Text))
            {
                MessageBox.Show("Enter Category Name First!","Name Missing",MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                if (MainForm.TasksCategories.ContainsKey(tbCategoryName.Text))
                {
                    MessageBox.Show("Category Name Already Exist!", "Already Exist", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    MainForm.TasksCategories.Add(tbCategoryName.Text, new List<TaskInfo>()); // adding a key-value to the dictionary
                    this.Close();
                }
            }
        }
    }
}
