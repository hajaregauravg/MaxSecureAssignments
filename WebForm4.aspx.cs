using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Diagnostics;

namespace WebApplication1
{
    public partial class WebForm4 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void delete_Button_Click(object sender, EventArgs e)
        {
            string sp_delete = "";
            SqlConnection con = new SqlConnection(@"Data Source=TEST\MSSQLSERVER1; Initial Catalog= My_database; AttachDbFilename=C:\Program Files\Microsoft SQL Server\MSSQL14.MSSQLSERVER1\MSSQL\DATA\My_database.mdf;Integrated Security=True");
            sp_delete = "DELETE FROM creds WHERE ID = (SELECT ID FROM creds WHERE Login_ID = (@Login_ID))";
            SqlCommand cmd = new SqlCommand(sp_delete, con);
            cmd.Parameters.AddWithValue("@Login_ID", username_TextBox.Text);
            con.Open();
            int i = cmd.ExecuteNonQuery();

            con.Close();
            if (i != 0)
            {
                Debug.WriteLine("Data Updated");
            }

            Server.Transfer("WebForm1.aspx");
        }
    }
}